<<<<<<<< HEAD:scene/3d/marker_3d.cpp
/**************************************************************************/
/*  marker_3d.cpp                                                         */
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

#include "marker_3d.h"

void Marker3D::set_gizmo_extents(real_t p_extents) {
	if (Math::is_equal_approx(gizmo_extents, p_extents)) {
		return;
	}
	gizmo_extents = p_extents;
	update_gizmos();
}

real_t Marker3D::get_gizmo_extents() const {
	return gizmo_extents;
}

void Marker3D::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_gizmo_extents", "extents"), &Marker3D::set_gizmo_extents);
	ClassDB::bind_method(D_METHOD("get_gizmo_extents"), &Marker3D::get_gizmo_extents);

	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "gizmo_extents", PROPERTY_HINT_RANGE, "0,10,0.01,or_greater,suffix:m"), "set_gizmo_extents", "get_gizmo_extents");
}

Marker3D::Marker3D() {
}
========
/*************************************************************************/
/*  fbx_bone.cpp                                                         */
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

#include "fbx_bone.h"

#include "fbx_node.h"
#include "import_state.h"

Ref<FBXNode> FBXSkinDeformer::get_link(const ImportState &state) const {
	print_verbose("bone name: " + bone->bone_name);

	// safe for when deformers must be polyfilled when skin has different count of binds to bones in the scene ;)
	if (!cluster) {
		return nullptr;
	}

	ERR_FAIL_COND_V_MSG(cluster->TargetNode() == nullptr, nullptr, "bone has invalid target node");

	Ref<FBXNode> link_node;
	uint64_t id = cluster->TargetNode()->ID();
	if (state.fbx_target_map.has(id)) {
		link_node = state.fbx_target_map[id];
	} else {
		print_error("link node not found for " + itos(id));
	}

	// the node in space this is for, like if it's FOR a target.
	return link_node;
}
>>>>>>>> 6fed1ffa313c6760fa88b368ae580378daaef0f0:modules/fbx/data/fbx_bone.cpp
