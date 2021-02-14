/*
   Copyright (C) 2021 FPT Software.

   This file is part of GnuCOBOL.

   The GnuCOBOL compiler is free software: you can redistribute it
   and/or modify it under the terms of the GNU General Public License
   as published by the Free Software Foundation, either version 3 of the
   License, or (at your option) any later version.

   GnuCOBOL is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with GnuCOBOL.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "cobc.h"
#include "tree.h"

#include <stdarg.h>

static FILE *output_target;

void
cb_init_codegen_cam (void)
{
	output_target = NULL;
}

static void
output (const char *fmt, ...)
{
	va_list ap;

	if (output_target) {
		va_start (ap, fmt);
		vfprintf (output_target, fmt, ap);
		va_end (ap);
	}
}

void
codegen_cam_init (struct cb_program *prog)
{
	output_target = yyout;
}

void
codegen_cam (struct cb_program *prog, const char *translate_name)
{
	codegen_cam_init (prog);
}