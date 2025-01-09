#include <obs-module.h>

OBS_DECLARE_MODULE()
OBS_MODULE_USE_DEFAULT_LOCALE("obs-vkvideo", "en-US")

MODULE_EXPORT const char *obs_module_description(void)
{
	return "Vulkan Video Encoder Plugin";
}

bool obs_module_load(void)
{
	return true;
}

void obs_module_unload(void)
{
}
