<<<<<<<< HEAD:platform/ios/godot_ios.mm
/**************************************************************************/
/*  godot_ios.mm                                                          */
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
========
/*************************************************************************/
/*  godot_iphone.mm                                                      */
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
>>>>>>>> 6fed1ffa313c6760fa88b368ae580378daaef0f0:platform/ios/godot_iphone.mm

#import "os_ios.h"

#include "core/string/ustring.h"
#include "main/main.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>

static OS_IOS *os = nullptr;

int add_path(int p_argc, char **p_args) {
	NSString *str = [[[NSBundle mainBundle] infoDictionary] objectForKey:@"godot_path"];
	if (!str) {
		return p_argc;
	}

	p_args[p_argc++] = (char *)"--path";
	p_args[p_argc++] = (char *)[str cStringUsingEncoding:NSUTF8StringEncoding];
<<<<<<<< HEAD:platform/ios/godot_ios.mm
	p_args[p_argc] = nullptr;
========
	p_args[p_argc] = NULL;
>>>>>>>> 6fed1ffa313c6760fa88b368ae580378daaef0f0:platform/ios/godot_iphone.mm

	return p_argc;
}

int add_cmdline(int p_argc, char **p_args) {
	NSArray *arr = [[[NSBundle mainBundle] infoDictionary] objectForKey:@"godot_cmdline"];
	if (!arr) {
		return p_argc;
	}

	for (NSUInteger i = 0; i < [arr count]; i++) {
		NSString *str = [arr objectAtIndex:i];
		if (!str) {
			continue;
		}
		p_args[p_argc++] = (char *)[str cStringUsingEncoding:NSUTF8StringEncoding];
	}

<<<<<<<< HEAD:platform/ios/godot_ios.mm
	p_args[p_argc] = nullptr;
========
	p_args[p_argc] = NULL;
>>>>>>>> 6fed1ffa313c6760fa88b368ae580378daaef0f0:platform/ios/godot_iphone.mm

	return p_argc;
}

<<<<<<<< HEAD:platform/ios/godot_ios.mm
int ios_main(int argc, char **argv) {
	size_t len = strlen(argv[0]);

	while (len--) {
		if (argv[0][len] == '/') {
			break;
		}
========
int iphone_main(int argc, char **argv, String data_dir, String cache_dir) {
	size_t len = strlen(argv[0]);

	while (len--) {
		if (argv[0][len] == '/')
			break;
>>>>>>>> 6fed1ffa313c6760fa88b368ae580378daaef0f0:platform/ios/godot_iphone.mm
	}

	if (len >= 0) {
		char path[512];
		memcpy(path, argv[0], len > sizeof(path) ? sizeof(path) : len);
		path[len] = 0;
		chdir(path);
	}

<<<<<<<< HEAD:platform/ios/godot_ios.mm
	os = new OS_IOS();

	// We must override main when testing is enabled
	TEST_MAIN_OVERRIDE
========
	printf("godot_iphone %s\n", argv[0]);
	char cwd[512];
	getcwd(cwd, sizeof(cwd));
	printf("cwd %s\n", cwd);
	os = new OSIPhone(data_dir, cache_dir);
>>>>>>>> 6fed1ffa313c6760fa88b368ae580378daaef0f0:platform/ios/godot_iphone.mm

	char *fargv[64];
	for (int i = 0; i < argc; i++) {
		fargv[i] = argv[i];
	}
<<<<<<<< HEAD:platform/ios/godot_ios.mm
	fargv[argc] = nullptr;
========
	fargv[argc] = NULL;
>>>>>>>> 6fed1ffa313c6760fa88b368ae580378daaef0f0:platform/ios/godot_iphone.mm
	argc = add_path(argc, fargv);
	argc = add_cmdline(argc, fargv);

	Error err = Main::setup(fargv[0], argc - 1, &fargv[1], false);
<<<<<<<< HEAD:platform/ios/godot_ios.mm
========
	printf("setup %i\n", err);
>>>>>>>> 6fed1ffa313c6760fa88b368ae580378daaef0f0:platform/ios/godot_iphone.mm

	if (err == ERR_HELP) { // Returned by --help and --version, so success.
		return 0;
	} else if (err != OK) {
		return 255;
	}
<<<<<<<< HEAD:platform/ios/godot_ios.mm

	os->initialize_modules();
========
>>>>>>>> 6fed1ffa313c6760fa88b368ae580378daaef0f0:platform/ios/godot_iphone.mm

	return 0;
}

<<<<<<<< HEAD:platform/ios/godot_ios.mm
void ios_finish() {
========
void iphone_finish() {
	printf("iphone_finish\n");
>>>>>>>> 6fed1ffa313c6760fa88b368ae580378daaef0f0:platform/ios/godot_iphone.mm
	Main::cleanup();
	delete os;
}
