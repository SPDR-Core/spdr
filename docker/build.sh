#!/usr/bin/env bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd $DIR/..

DOCKER_IMAGE=${DOCKER_IMAGE:-spdrcore/spdr}
DOCKER_TAG=${DOCKER_TAG:-latest}

BUILD_DIR=${BUILD_DIR:-.}

rm docker/bin/*
mkdir docker/bin
cp $BUILD_DIR/src/spdrd docker/bin/
cp $BUILD_DIR/src/spdr-cli docker/bin/
cp $BUILD_DIR/src/spdr-tx docker/bin/
strip docker/bin/spdrd
strip docker/bin/spdr-cli
strip docker/bin/spdr-tx

docker build --pull -t $DOCKER_IMAGE:$DOCKER_TAG -f docker/Dockerfile docker
