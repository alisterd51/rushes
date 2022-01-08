#!/usr/bin/env sh

nm -u libunit.a | grep -v " ft_\|\.o:\| _" | grep "U"
