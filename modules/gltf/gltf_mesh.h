<<<<<<<< HEAD:editor/import/post_import_plugin_skeleton_track_organizer.h
/**************************************************************************/
/*  post_import_plugin_skeleton_track_organizer.h                         */
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

#ifndef POST_IMPORT_PLUGIN_SKELETON_TRACK_ORGANIZER_H
#define POST_IMPORT_PLUGIN_SKELETON_TRACK_ORGANIZER_H

#include "resource_importer_scene.h"

class PostImportPluginSkeletonTrackOrganizer : public EditorScenePostImportPlugin {
	GDCLASS(PostImportPluginSkeletonTrackOrganizer, EditorScenePostImportPlugin);

public:
	virtual void get_internal_import_options(InternalImportCategory p_category, List<ResourceImporter::ImportOption> *r_options) override;
	virtual void internal_process(InternalImportCategory p_category, Node *p_base_scene, Node *p_node, Ref<Resource> p_resource, const Dictionary &p_options) override;

	PostImportPluginSkeletonTrackOrganizer();
};

#endif // POST_IMPORT_PLUGIN_SKELETON_TRACK_ORGANIZER_H
========
/*************************************************************************/
/*  gltf_mesh.h                                                          */
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

#ifndef GLTF_MESH_H
#define GLTF_MESH_H

#include "core/resource.h"
#include "scene/resources/mesh.h"

class GLTFMesh : public Resource {
	GDCLASS(GLTFMesh, Resource);

private:
	Ref<ArrayMesh> mesh;
	Vector<float> blend_weights;
	Array instance_materials;

protected:
	static void _bind_methods();

public:
	Ref<ArrayMesh> get_mesh();
	void set_mesh(Ref<ArrayMesh> p_mesh);
	Vector<float> get_blend_weights();
	void set_blend_weights(Vector<float> p_blend_weights);
	Array get_instance_materials();
	void set_instance_materials(Array p_instance_materials);
};

#endif // GLTF_MESH_H
>>>>>>>> 6fed1ffa313c6760fa88b368ae580378daaef0f0:modules/gltf/gltf_mesh.h
