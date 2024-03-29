/* Copyright (c) 2013-2014, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#define pr_fmt(fmt) "MSM-SENSOR-INIT %s:%d " fmt "\n", __func__, __LINE__

/* Header files */
#include <mach/gpiomux.h>
#include "msm_sensor_init.h"
#include "msm_sensor_driver.h"
#include "msm_sensor.h"
#include "msm_sd.h"

/* Logging macro */
/*#define CONFIG_MSMB_CAMERA_DEBUG*/
#undef CDBG
#ifdef CONFIG_MSMB_CAMERA_DEBUG
#define CDBG(fmt, args...) pr_err(fmt, ##args)
#else
#define CDBG(fmt, args...) do { } while (0)
#endif

struct class *camera_class;

static struct msm_sensor_init_t *s_init;

/* Static function declaration */
static long msm_sensor_init_subdev_ioctl(struct v4l2_subdev *sd,
	unsigned int cmd, void *arg);

/* Static structure declaration */
static struct v4l2_subdev_core_ops msm_sensor_init_subdev_core_ops = {
	.ioctl = msm_sensor_init_subdev_ioctl,
};

static struct v4l2_subdev_ops msm_sensor_init_subdev_ops = {
	.core = &msm_sensor_init_subdev_core_ops,
};

static const struct v4l2_subdev_internal_ops msm_sensor_init_internal_ops;

static int msm_sensor_wait_for_probe_done(struct msm_sensor_init_t *s_init)
{
	int rc;
	int tm = 10000;

	if (s_init->module_init_status == 1) {
		pr_err("msm_cam_get_module_init_status -2\n");
		return 0;
	}
	rc = wait_event_interruptible_timeout(s_init->state_wait,
		(s_init->module_init_status == 1), msecs_to_jiffies(tm));
	if (rc < 0)
		pr_err("%s:%d wait failed\n", __func__, __LINE__);
	else if (rc == 0)
		pr_err("%s:%d wait timeout\n", __func__, __LINE__);

	return rc;
}

/* Static function definition */
static int32_t msm_sensor_driver_cmd(struct msm_sensor_init_t *s_init,
	void *arg)
{
	int32_t                      rc = 0;
	struct sensor_init_cfg_data *cfg = (struct sensor_init_cfg_data *)arg;

	/* Validate input parameters */
	if (!s_init || !cfg) {
		pr_err("failed: s_init %p cfg %p", s_init, cfg);
		return -EINVAL;
	}

	switch (cfg->cfgtype) {
	case CFG_SINIT_PROBE:
		mutex_lock(&s_init->imutex);
		s_init->module_init_status = 0;
		rc = msm_sensor_driver_probe(cfg->cfg.setting);
		mutex_unlock(&s_init->imutex);
		if (rc < 0)
			pr_err("failed: msm_sensor_driver_probe rc %d", rc);
		break;

	case CFG_SINIT_PROBE_DONE:
		s_init->module_init_status = 1;
		wake_up(&s_init->state_wait);
		break;

	case CFG_SINIT_PROBE_WAIT_DONE:
		msm_sensor_wait_for_probe_done(s_init);
		break;

	default:
		pr_err("default");
		break;
	}

	return rc;
}

static long msm_sensor_init_subdev_ioctl(struct v4l2_subdev *sd,
	unsigned int cmd, void *arg)
{
	int32_t rc = 0;
	struct msm_sensor_init_t *s_init = v4l2_get_subdevdata(sd);
	CDBG("Enter");

	/* Validate input parameters */
	if (!s_init) {
		pr_err("failed: s_init %p", s_init);
		return -EINVAL;
	}

	switch (cmd) {
	case VIDIOC_MSM_SENSOR_INIT_CFG:
		rc = msm_sensor_driver_cmd(s_init, arg);
		break;

	default:
		pr_err_ratelimited("default\n");
		break;
	}

	return rc;
}


static ssize_t back_camera_type_show(struct device *dev,
			struct device_attribute *attr, char *buf)
{

#if defined(CONFIG_MACH_LEVI_CHN_OPEN) || defined (CONFIG_SEC_VASTA3G_PROJECT)
	char type[] = "SONY_IMX219\n";
#else
	char type[] = "SONY_IMX135\n";
#endif

	 return snprintf(buf, sizeof(type), "%s", type);
}

static ssize_t front_camera_type_show(struct device *dev,
			struct device_attribute *attr, char *buf)
{

#if defined(CONFIG_MACH_LEVI_CHN_OPEN)
	char cam_type[] = "SLSI_S5K6A3YX\n";

#else
	char cam_type[] = "SLSI_S5K5E3YX\n";
#endif

	return snprintf(buf, sizeof(cam_type), "%s", cam_type);
}

char cam_fw_ver[25] = "NULL NULL\n";
static ssize_t back_camera_firmware_show(struct device *dev,
			struct device_attribute *attr, char *buf)
{
	CDBG("[FW_DBG] cam_fw_ver : %s\n", cam_fw_ver);
	return snprintf(buf, sizeof(cam_fw_ver), "%s", cam_fw_ver);
}

static ssize_t back_camera_firmware_store(struct device *dev,
		struct device_attribute *attr, const char *buf, size_t size)
{
	CDBG("[FW_DBG] buf : %s\n", buf);
	snprintf(cam_fw_ver, sizeof(cam_fw_ver), "%s", buf);

	return size;
}

char cam_load_fw[25] = "NULL\n";
static ssize_t back_camera_firmware_load_show(struct device *dev,
			struct device_attribute *attr, char *buf)
{
	CDBG("[FW_DBG] cam_load_fw : %s\n", cam_load_fw);
	return snprintf(buf, sizeof(cam_load_fw), "%s", cam_load_fw);
}

static ssize_t back_camera_firmware_load_store(struct device *dev,
			struct device_attribute *attr, const char *buf, size_t size)
{
	CDBG("[FW_DBG] buf : %s\n", buf);
	snprintf(cam_load_fw, sizeof(cam_load_fw), "%s\n", buf);
	return size;
}

char cam_fw_full_ver[40] = "NULL NULL NULL\n";//multi module
static ssize_t back_camera_firmware_full_show(struct device *dev,
			struct device_attribute *attr, char *buf)
{
	CDBG("[FW_DBG] cam_fw_ver : %s\n", cam_fw_full_ver);
	return snprintf(buf, sizeof(cam_fw_full_ver), "%s", cam_fw_full_ver);
}

static ssize_t back_camera_firmware_full_store(struct device *dev,
			struct device_attribute *attr, const char *buf, size_t size)
{
	CDBG("[FW_DBG] buf : %s\n", buf);
	snprintf(cam_fw_full_ver, sizeof(cam_fw_full_ver), "%s", buf);
	return size;
}

static ssize_t rear_camera_isp_core_show(struct device *dev,
			struct device_attribute *attr, char *buf)
{
	char isp_core[] = "0.9000\n";
	return  snprintf(buf, sizeof(isp_core), "%s", isp_core);
}

char cam_fw_user_ver[40] = "NULL NULL\n";//multi module
static ssize_t back_camera_firmware_user_show(struct device *dev,
					 struct device_attribute *attr, char *buf)
{
	CDBG("[FW_DBG] cam_fw_ver : %s\n", cam_fw_user_ver);
	return snprintf(buf, sizeof(cam_fw_user_ver), "%s", cam_fw_user_ver);
}

static ssize_t back_camera_firmware_user_store(struct device *dev,
					  struct device_attribute *attr, const char *buf, size_t size)
{
	CDBG("[FW_DBG] buf : %s\n", buf);
	snprintf(cam_fw_user_ver, sizeof(cam_fw_user_ver), "%s", buf);

	return size;
}

char cam_fw_factory_ver[40] = "NULL NULL\n";//multi module
static ssize_t back_camera_firmware_factory_show(struct device *dev,
					 struct device_attribute *attr, char *buf)
{
	CDBG("[FW_DBG] cam_fw_ver : %s\n", cam_fw_factory_ver);
	return snprintf(buf, sizeof(cam_fw_factory_ver), "%s", cam_fw_factory_ver);
}

static ssize_t back_camera_firmware_factory_store(struct device *dev,
					  struct device_attribute *attr, const char *buf, size_t size)
{
	CDBG("[FW_DBG] buf : %s\n", buf);
	snprintf(cam_fw_factory_ver, sizeof(cam_fw_factory_ver), "%s", buf);

	return size;
}

#if defined(CONFIG_SEC_A7_PROJECT) || defined(CONFIG_SEC_A3_PROJECT)
char front_cam_fw_ver[25] = "S5K5E3YX N\n";
#else
char front_cam_fw_ver[25] = "NULL NULL\n";
#endif
static ssize_t front_camera_firmware_show(struct device *dev,
			struct device_attribute *attr, char *buf)
{
	CDBG("[FW_DBG] front_cam_fw_ver : %s\n", front_cam_fw_ver);
	return snprintf(buf, sizeof(front_cam_fw_ver), "%s", front_cam_fw_ver);
}

static ssize_t front_camera_firmware_store(struct device *dev,
		struct device_attribute *attr, const char *buf, size_t size)
{
	CDBG("[FW_DBG] buf : %s\n", buf);
	snprintf(front_cam_fw_ver, sizeof(front_cam_fw_ver), "%s", buf);

	return size;
}

char front_cam_load_fw[25] = "NULL\n";
static ssize_t front_camera_firmware_load_show(struct device *dev,
			struct device_attribute *attr, char *buf)
{
	CDBG("[FW_DBG] cam_load_fw : %s\n", front_cam_load_fw);
	return snprintf(buf, sizeof(front_cam_load_fw), "%s", front_cam_load_fw);
}
static ssize_t front_camera_firmware_load_store(struct device *dev,
			struct device_attribute *attr, const char *buf, size_t size)
{
	CDBG("[FW_DBG] buf : %s\n", buf);
	snprintf(front_cam_load_fw, sizeof(front_cam_load_fw), "%s\n", buf);
	return size;
}

char front_cam_fw_full_ver[40] = "NULL NULL NULL\n";//multi module
static ssize_t front_camera_firmware_full_show(struct device *dev,
			struct device_attribute *attr, char *buf)
{
	CDBG("[FW_DBG] front_cam_fw_full_ver : %s\n", front_cam_fw_full_ver);
	return snprintf(buf, sizeof(front_cam_fw_full_ver), "%s", front_cam_fw_full_ver);
}
static ssize_t front_camera_firmware_full_store(struct device *dev,
			struct device_attribute *attr, const char *buf, size_t size)
{
	CDBG("[FW_DBG] buf : %s\n", buf);
	snprintf(front_cam_fw_full_ver, sizeof(front_cam_fw_full_ver), "%s", buf);
	return size;
}

static DEVICE_ATTR(rear_camtype, S_IRUGO, back_camera_type_show, NULL);
static DEVICE_ATTR(rear_camfw, S_IRUGO|S_IWUSR|S_IWGRP,
		back_camera_firmware_show, back_camera_firmware_store);
static DEVICE_ATTR(rear_camfw_load, S_IRUGO|S_IWUSR|S_IWGRP,
		back_camera_firmware_load_show, back_camera_firmware_load_store);
static DEVICE_ATTR(rear_camfw_full, S_IRUGO | S_IWUSR | S_IWGRP,
		back_camera_firmware_full_show, back_camera_firmware_full_store);
static DEVICE_ATTR(isp_core, S_IRUGO, rear_camera_isp_core_show, NULL);
static DEVICE_ATTR(front_camtype, S_IRUGO, front_camera_type_show, NULL);
static DEVICE_ATTR(front_camfw, S_IRUGO|S_IWUSR|S_IWGRP,
		front_camera_firmware_show, front_camera_firmware_store);
static DEVICE_ATTR(front_camfw_load, S_IRUGO|S_IWUSR|S_IWGRP,
		front_camera_firmware_load_show, front_camera_firmware_load_store);
static DEVICE_ATTR(front_camfw_full, S_IRUGO | S_IWUSR | S_IWGRP,
		front_camera_firmware_full_show, front_camera_firmware_full_store);
static DEVICE_ATTR(rear_checkfw_user, S_IRUGO|S_IWUSR|S_IWGRP,
		back_camera_firmware_user_show, back_camera_firmware_user_store);
static DEVICE_ATTR(rear_checkfw_factory, S_IRUGO|S_IWUSR|S_IWGRP,
		back_camera_firmware_factory_show, back_camera_firmware_factory_store);

static int __init msm_sensor_init_module(void)
{
	struct msm_sensor_init_t *s_init = NULL;
	struct device			*cam_dev_back;
	struct device			*cam_dev_front;
	int rc = 0;
	camera_class = class_create(THIS_MODULE, "camera");
	if (IS_ERR(camera_class))
		pr_err("failed to create device cam_dev_rear!\n");

	/* Allocate memory for msm_sensor_init control structure */
	s_init = kzalloc(sizeof(struct msm_sensor_init_t), GFP_KERNEL);
	if (!s_init) {
		class_destroy(camera_class);
		pr_err("failed: no memory s_init %p", NULL);
		return -ENOMEM;
	}

	pr_err("MSM_SENSOR_INIT_MODULE %p", NULL);

	/* Initialize mutex */
	mutex_init(&s_init->imutex);

	/* Create /dev/v4l-subdevX for msm_sensor_init */
	v4l2_subdev_init(&s_init->msm_sd.sd, &msm_sensor_init_subdev_ops);
	snprintf(s_init->msm_sd.sd.name, sizeof(s_init->msm_sd.sd.name), "%s",
		"msm_sensor_init");
	v4l2_set_subdevdata(&s_init->msm_sd.sd, s_init);
	s_init->msm_sd.sd.internal_ops = &msm_sensor_init_internal_ops;
	s_init->msm_sd.sd.flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
	rc = media_entity_init(&s_init->msm_sd.sd.entity, 0, NULL, 0);
	if (rc < 0)
		goto entity_fail;
	s_init->msm_sd.sd.entity.type = MEDIA_ENT_T_V4L2_SUBDEV;
	s_init->msm_sd.sd.entity.group_id = MSM_CAMERA_SUBDEV_SENSOR_INIT;
	s_init->msm_sd.sd.entity.name = s_init->msm_sd.sd.name;
	s_init->msm_sd.close_seq = MSM_SD_CLOSE_2ND_CATEGORY | 0x6;
	rc = msm_sd_register(&s_init->msm_sd);
	if (rc < 0)
		goto msm_sd_register_fail;

	cam_dev_back = device_create(camera_class, NULL,
		1, NULL, "rear");
	if (IS_ERR(cam_dev_back)) {
		printk("Failed to create cam_dev_back device!\n");
		goto device_create_fail;
	}

	if (device_create_file(cam_dev_back, &dev_attr_rear_camtype) < 0) {
		printk("Failed to create device file!(%s)!\n",
			dev_attr_rear_camtype.attr.name);
		goto device_create_fail;
	}
	if (device_create_file(cam_dev_back, &dev_attr_rear_camfw) < 0) {
		printk("Failed to create device file!(%s)!\n",
			dev_attr_rear_camfw.attr.name);
		goto device_create_fail;
	}

	if (device_create_file(cam_dev_back, &dev_attr_isp_core) < 0) {
		printk("Failed to create device file!(%s)!\n",
			dev_attr_isp_core.attr.name);
		goto device_create_fail;
	}

	if (device_create_file(cam_dev_back, &dev_attr_rear_camfw_load) < 0) {
		printk("Failed to create device file!(%s)!\n",
			dev_attr_rear_camfw_load.attr.name);
		goto device_create_fail;
	}

	if (device_create_file(cam_dev_back, &dev_attr_rear_camfw_full) < 0) {
	    printk("Failed to create device file!(%s)!\n",
		    dev_attr_rear_camfw_full.attr.name);
		goto device_create_fail;
	}

	if (device_create_file(cam_dev_back, &dev_attr_rear_checkfw_user) < 0) {
		printk("Failed to create device file!(%s)!\n",
			dev_attr_rear_checkfw_user.attr.name);
		rc = -ENODEV;
		goto device_create_fail;
	}

	if (device_create_file(cam_dev_back, &dev_attr_rear_checkfw_factory) < 0) {
		printk("Failed to create device file!(%s)!\n",
			dev_attr_rear_checkfw_factory.attr.name);
		rc = -ENODEV;
		goto device_create_fail;
	}

	cam_dev_front = device_create(camera_class, NULL,
		2, NULL, "front");
	if (IS_ERR(cam_dev_front)) {
		printk("Failed to create cam_dev_front device!");
		goto device_create_fail;
	}

	if (device_create_file(cam_dev_front, &dev_attr_front_camtype) < 0) {
		printk("Failed to create device file!(%s)!\n",
			dev_attr_front_camtype.attr.name);
		goto device_create_fail;
	}
	if (device_create_file(cam_dev_front, &dev_attr_front_camfw) < 0) {
		printk("Failed to create device file!(%s)!\n",
			dev_attr_front_camfw.attr.name);
		goto device_create_fail;
	}
	if (device_create_file(cam_dev_front, &dev_attr_front_camfw_load) < 0) {
		printk("Failed to create device file!(%s)!\n",
			dev_attr_rear_camfw_load.attr.name);
		goto device_create_fail;
	}
	if (device_create_file(cam_dev_front, &dev_attr_front_camfw_full) < 0) {
	    printk("Failed to create device file!(%s)!\n",
		    dev_attr_rear_camfw_full.attr.name);
		goto device_create_fail;
	}

	init_waitqueue_head(&s_init->state_wait);

	return 0;
device_create_fail:
	msm_sd_unregister(&s_init->msm_sd);
msm_sd_register_fail:
	media_entity_cleanup(&s_init->msm_sd.sd.entity);
entity_fail:
	mutex_destroy(&s_init->imutex);
	kfree(s_init);
	class_destroy(camera_class);
	return rc;
}

static void __exit msm_sensor_exit_module(void)
{
	msm_sd_unregister(&s_init->msm_sd);
	mutex_destroy(&s_init->imutex);
	kfree(s_init);
	return;
}

module_init(msm_sensor_init_module);
module_exit(msm_sensor_exit_module);
MODULE_DESCRIPTION("msm_sensor_init");
MODULE_LICENSE("GPL v2");
