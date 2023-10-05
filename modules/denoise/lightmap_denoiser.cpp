<<<<<<<< HEAD:drivers/gles3/environment/fog.cpp
/**************************************************************************/
/*  fog.cpp                                                               */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#ifdef GLES3_ENABLED

#include "fog.h"

using namespace GLES3;

/* FOG */

RID Fog::fog_volume_allocate() {
	return RID();
}

void Fog::fog_volume_initialize(RID p_rid) {
}

void Fog::fog_volume_free(RID p_rid) {
}

void Fog::fog_volume_set_shape(RID p_fog_volume, RS::FogVolumeShape p_shape) {
}

void Fog::fog_volume_set_size(RID p_fog_volume, const Vector3 &p_size) {
}

void Fog::fog_volume_set_material(RID p_fog_volume, RID p_material) {
========
/*************************************************************************/
/*  lightmap_denoiser.cpp                                                */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                      https://godotengine.org                          */
/*************************************************************************/
/* Copyright (c) 2007-2022 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2022 Godot Engine contributors (cf. AUTHORS.md).   */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/

#include "lightmap_denoiser.h"

#include "denoise_wrapper.h"

LightmapDenoiser *LightmapDenoiserOIDN::create_oidn_denoiser() {
	return memnew(LightmapDenoiserOIDN);
}

void LightmapDenoiserOIDN::make_default_denoiser() {
	create_function = create_oidn_denoiser;
}

Ref<Image> LightmapDenoiserOIDN::denoise_image(const Ref<Image> &p_image) {
	Ref<Image> img = p_image->duplicate();

	img->convert(Image::FORMAT_RGBF);

	PoolByteArray data = img->get_data();
	{
		PoolByteArray::Write w = data.write();
		if (!oidn_denoise(device, (float *)w.ptr(), img->get_width(), img->get_height())) {
			return p_image;
		}
	}

	img->create(img->get_width(), img->get_height(), false, img->get_format(), data);
	return img;
}

LightmapDenoiserOIDN::LightmapDenoiserOIDN() {
	device = oidn_denoiser_init();
}

LightmapDenoiserOIDN::~LightmapDenoiserOIDN() {
	oidn_denoiser_finish(device);
>>>>>>>> 6fed1ffa313c6760fa88b368ae580378daaef0f0:modules/denoise/lightmap_denoiser.cpp
}

AABB Fog::fog_volume_get_aabb(RID p_fog_volume) const {
	return AABB();
}

RS::FogVolumeShape Fog::fog_volume_get_shape(RID p_fog_volume) const {
	return RS::FOG_VOLUME_SHAPE_BOX;
}

#endif // GLES3_ENABLED
