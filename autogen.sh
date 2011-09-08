#!/bin/sh
#-
# Copyright (C) 2011 Mikolaj Izdebski
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#

set -e

# Option -r removes autogenerated files.
if test x"$1" = x-r; then
  rm -Rf lib m4 build-aux autom4te.cache
  rm -f configure aclocal.m4 INSTALL
  for dir in . src yambi; do rm -f $dir/Makefile.in; done
  exit
fi

set -x
gnulib-tool --add-import pthread utimens warnings timespec-add timespec-sub \
    dtotimespec stat-time lstat malloc-gnu fprintf-posix inttypes

aclocal -Im4
autoconf
autoheader
automake --add-missing --copy
