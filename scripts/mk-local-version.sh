#!/bin/bash -

################################################################################
# Copyright (c) 2022 - 2024 TQ-Systems GmbH <oss@ew.tq-group.com>,
# D-82229 Seefeld, Germany.
# author: Markus Niebel
###############################################################################

###############################################################################
#
# File:        mk-local-version.sh
# Description: Write version info to stdout
#
# License:     GPLv2
#
###############################################################################
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
#
###############################################################################

# DEBUGGING
set -e
set -C # noclobber

# Internal variables and initializations.
readonly PROGRAM="$(basename "$0")"

usage() {
	echo "Usage: ${PROGRAM} [--help]"
}

 # Create a place to store our work's progress
main () {
	local STAMP="local-version"
	local HAVE_GIT="0"

	if [ "$#" -ne "0" ]; then
		usage
		return 1
	fi

	if git status >/dev/null 2>/dev/null; then
		HAVE_GIT="1"
	fi

	if [ "${HAVE_GIT}" -ne "0" ]; then
		local GITHEAD=""
		local GITATAG=""

		GITHEAD="$(git rev-parse --verify HEAD 2>/dev/null)"
		GITATAG="$(git describe 2>/dev/null)"
		local IS_GIT_TAG="0"

		if git show-ref --quiet --tags "${GITATAG}" 2>/dev/null; then
			IS_GIT_TAG="1"
		fi
		if [ "${IS_GIT_TAG}" -gt "0" ]; then
			STAMP=${GITATAG};
		elif [ -n "${GITATAG}" ]; then
			STAMP=$(echo "${GITATAG}" | \
				awk -F- '{ printf("%s", $1); for (i = 2; i <= NF - 2; i++) { printf("-%s", $i) } }')
			STAMP=${STAMP}$(echo "${GITATAG}" | \
				awk -F- '{ if (NF >= 3) printf("-%05d-%s", $(NF-1),$(NF));}')
		else
			STAMP="-g${GITHEAD:0:12}"
		fi
		if [ -n "$(git status --porcelain)" ]; then
			STAMP="${STAMP}"-dirty
		fi
	fi

	echo "${STAMP}"

	return 0
}

main "$@"
