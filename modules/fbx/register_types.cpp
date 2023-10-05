<<<<<<<< HEAD:modules/raycast/register_types.cpp
/**************************************************************************/
/*  register_types.cpp                                                    */
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

#include "register_types.h"

#include "lightmap_raycaster_embree.h"
#include "raycast_occlusion_cull.h"
#include "static_raycaster_embree.h"

RaycastOcclusionCull *raycast_occlusion_cull = nullptr;

void initialize_raycast_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

#ifdef TOOLS_ENABLED
	LightmapRaycasterEmbree::make_default_raycaster();
	StaticRaycasterEmbree::make_default_raycaster();
========
/*************************************************************************/
/*  register_types.cpp                                                   */
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

#include "register_types.h"

#include "editor/editor_node.h"
#include "editor_scene_importer_fbx.h"

#ifdef TOOLS_ENABLED
static void _editor_init() {
	Ref<EditorSceneImporterFBX> import_fbx;
	import_fbx.instance();
	ResourceImporterScene::get_singleton()->add_importer(import_fbx);
}
>>>>>>>> 6fed1ffa313c6760fa88b368ae580378daaef0f0:modules/fbx/register_types.cpp
#endif
	raycast_occlusion_cull = memnew(RaycastOcclusionCull);
}

<<<<<<<< HEAD:modules/raycast/register_types.cpp
void uninitialize_raycast_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	if (raycast_occlusion_cull) {
		memdelete(raycast_occlusion_cull);
	}
#ifdef TOOLS_ENABLED
	StaticRaycasterEmbree::free();
#endif
}
========
void register_fbx_types() {
#ifdef TOOLS_ENABLED
	ClassDB::APIType prev_api = ClassDB::get_current_api();
	ClassDB::set_current_api(ClassDB::API_EDITOR);

	ClassDB::register_class<EditorSceneImporterFBX>();

	ClassDB::set_current_api(prev_api);

	EditorNode::add_init_callback(_editor_init);
#endif
}

void unregister_fbx_types() {
}
>>>>>>>> 6fed1ffa313c6760fa88b368ae580378daaef0f0:modules/fbx/register_types.cpp
