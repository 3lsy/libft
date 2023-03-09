#!/usr/bin/env bash

if [ ! -z "$1" ]; then
	git commit -m "$1" &&
		git push origin dev &&
		git checkout main &&
		git merge dev
else
	echo "Usage: ./pr.sh <commit message>"
	ehco "WARNING: Only run on the dev branch when merging with the master branch!"
fi
