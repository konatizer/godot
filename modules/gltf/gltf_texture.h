<<<<<<<< HEAD:scene/resources/style_box_line.h
/**************************************************************************/
/*  style_box_line.h                                                      */
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

#ifndef STYLE_BOX_LINE_H
#define STYLE_BOX_LINE_H

#include "scene/resources/style_box.h"

class StyleBoxLine : public StyleBox {
	GDCLASS(StyleBoxLine, StyleBox);
	Color color;
	int thickness = 1;
	bool vertical = false;
	float grow_begin = 1.0;
	float grow_end = 1.0;
========
/*************************************************************************/
/*  gltf_texture.h                                                       */
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

#ifndef GLTF_TEXTURE_H
#define GLTF_TEXTURE_H

#include "core/resource.h"

#include "gltf_document.h"

class GLTFTexture : public Resource {
	GDCLASS(GLTFTexture, Resource);

private:
	GLTFImageIndex src_image = 0;
>>>>>>>> 6fed1ffa313c6760fa88b368ae580378daaef0f0:modules/gltf/gltf_texture.h

protected:
	virtual float get_style_margin(Side p_side) const override;
	static void _bind_methods();

public:
<<<<<<<< HEAD:scene/resources/style_box_line.h
	void set_color(const Color &p_color);
	Color get_color() const;

	void set_thickness(int p_thickness);
	int get_thickness() const;

	void set_vertical(bool p_vertical);
	bool is_vertical() const;

	void set_grow_begin(float p_grow);
	float get_grow_begin() const;

	void set_grow_end(float p_grow);
	float get_grow_end() const;

	virtual void draw(RID p_canvas_item, const Rect2 &p_rect) const override;

	StyleBoxLine();
	~StyleBoxLine();
};

#endif // STYLE_BOX_LINE_H
========
	GLTFImageIndex get_src_image() const;
	void set_src_image(GLTFImageIndex val);
};

#endif // GLTF_TEXTURE_H
>>>>>>>> 6fed1ffa313c6760fa88b368ae580378daaef0f0:modules/gltf/gltf_texture.h
