#!/bin/bash

docker build -t 1721900707/mysql-4.1-dev:0.0.0.0 . && docker run --rm -it  1721900707/mysql-4.1-dev:0.0.0.0 /bin/bash 