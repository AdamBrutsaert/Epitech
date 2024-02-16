#!/bin/bash

function create_epitech_header()
{
    local filename=$(basename $1)

    echo "/*" >> $1
    echo "** EPITECH PROJECT, 2023" >> $1
    echo "** $filename" >> $1
    echo "** File description:" >> $1
    echo "** $filename" >> $1
    echo "*/" >> $1
}

function create_header()
{
    touch $1
    create_epitech_header $1
    echo -e "\n#pragma once" >> $1
}

# Layer
function create_layer_headers()
{
    local HEADER="include/layers/$1.h"
    local HEADER_IMPL="include/layers/$1_impl.h"

    create_header $HEADER
    create_header $HEADER_IMPL

    # Header
    echo -e "\n#include \"engine.h\"" >> $HEADER
    echo -e "\n/**" >> $HEADER
    echo " * @brief Allocate a new $1 layer" >> $HEADER
    echo " *" >> $HEADER
    echo " * @return layer_t* the layer" >> $HEADER
    echo " */" >> $HEADER
    echo "layer_t *layer_$1_new(void);" >> $HEADER

    # Header impl
    echo -e "\n#include \"$1.h\"" >> $HEADER_IMPL
    echo -e "\ntypedef struct {" >> $HEADER_IMPL
    echo "} layer_$1_t;" >> $HEADER_IMPL

    echo -e "\nbool layer_$1_on_attach(layer_t *layer);" >> $HEADER_IMPL
    echo "void layer_$1_on_detach(layer_t *layer);" >> $HEADER_IMPL
    echo "bool layer_$1_on_event(layer_t *layer, sfEvent *event);" >> $HEADER_IMPL
    echo "bool layer_$1_on_update(layer_t *layer, float dt);" >> $HEADER_IMPL
    echo "void layer_$1_on_render(layer_t *layer);" >> $HEADER_IMPL
}

function create_layer_sources()
{
    local FOLDER="src/layers/$1"

    mkdir -p $FOLDER

    # New
    local NEW="$FOLDER/layer_$1_new.c"
    touch $NEW
    create_epitech_header $NEW
    echo -e "\n#include \"layers/$1_impl.h\"" >> $NEW
    echo -e "\nlayer_t *layer_$1_new(void)" >> $NEW
    echo "{" >> $NEW
    echo "    layer_t *layer = layer_new(sizeof(layer_$1_t));" >> $NEW
    echo -e "\n    if (layer == NULL)" >> $NEW
    echo "        return NULL;" >> $NEW
    echo "    layer_bind_on_attach(layer, layer_$1_on_attach);" >> $NEW
    echo "    layer_bind_on_detach(layer, layer_$1_on_detach);" >> $NEW
    echo "    layer_bind_on_event(layer, layer_$1_on_event);" >> $NEW
    echo "    layer_bind_on_update(layer, layer_$1_on_update);" >> $NEW
    echo "    layer_bind_on_render(layer, layer_$1_on_render);" >> $NEW
    echo "    return layer;" >> $NEW
    echo "}" >> $NEW

    # On attach
    local ON_ATTACH="$FOLDER/layer_$1_on_attach.c"
    touch $ON_ATTACH
    create_epitech_header $ON_ATTACH
    echo -e "\n#include \"layers/$1_impl.h\"" >> $ON_ATTACH
    echo -e "\nbool layer_$1_on_attach(layer_t *layer)" >> $ON_ATTACH
    echo "{" >> $ON_ATTACH
    echo "    return true;" >> $ON_ATTACH
    echo "}" >> $ON_ATTACH

    # On detach
    local ON_DETACH="$FOLDER/layer_$1_on_detach.c"
    touch $ON_DETACH
    create_epitech_header $ON_DETACH
    echo -e "\n#include \"layers/$1_impl.h\"" >> $ON_DETACH
    echo -e "\nvoid layer_$1_on_detach(layer_t *layer)" >> $ON_DETACH
    echo "{" >> $ON_DETACH
    echo "}" >> $ON_DETACH

    # On event
    local ON_EVENT="$FOLDER/layer_$1_on_event.c"
    touch $ON_EVENT
    create_epitech_header $ON_EVENT
    echo -e "\n#include \"layers/$1_impl.h\"" >> $ON_EVENT
    echo -e "\nbool layer_$1_on_event(layer_t *layer, sfEvent *event)" >> $ON_EVENT
    echo "{" >> $ON_EVENT
    echo "    return true;" >> $ON_EVENT
    echo "}" >> $ON_EVENT

    # On update
    local ON_UPDATE="$FOLDER/layer_$1_on_update.c"
    touch $ON_UPDATE
    create_epitech_header $ON_UPDATE
    echo -e "\n#include \"layers/$1_impl.h\"" >> $ON_UPDATE
    echo -e "\nbool layer_$1_on_update(layer_t *layer, float dt)" >> $ON_UPDATE
    echo "{" >> $ON_UPDATE
    echo "    return true;" >> $ON_UPDATE
    echo "}" >> $ON_UPDATE

    # On render
    local ON_RENDER="$FOLDER/layer_$1_on_render.c"
    touch $ON_RENDER
    create_epitech_header $ON_RENDER
    echo -e "\n#include \"layers/$1_impl.h\"" >> $ON_RENDER
    echo -e "\nvoid layer_$1_on_render(layer_t *layer)" >> $ON_RENDER
    echo "{" >> $ON_RENDER
    echo "}" >> $ON_RENDER
}

function create_layer()
{
    create_layer_headers $1
    create_layer_sources $1
}

# Entity
function create_entity_headers()
{
    local HEADER="include/entities/$1.h"
    local HEADER_IMPL="include/entities/$1_impl.h"

    create_header $HEADER
    create_header $HEADER_IMPL

    # Header
    echo -e "\n#include \"engine.h\"" >> $HEADER
    echo -e "\n/**" >> $HEADER
    echo " * @brief Allocate a new $1 entity" >> $HEADER
    echo " *" >> $HEADER
    echo " * @return entity_t* the entity" >> $HEADER
    echo " */" >> $HEADER
    echo "entity_t *entity_$1_new(void);" >> $HEADER

    # Header impl
    echo -e "\n#include \"$1.h\"" >> $HEADER_IMPL
    echo -e "\ntypedef struct {" >> $HEADER_IMPL
    echo "} entity_$1_t;" >> $HEADER_IMPL

    echo -e "\nbool entity_$1_on_attach(entity_t *entity);" >> $HEADER_IMPL
    echo "void entity_$1_on_detach(entity_t *entity);" >> $HEADER_IMPL
    echo "bool entity_$1_on_event(entity_t *entity, sfEvent *event);" >> $HEADER_IMPL
    echo "bool entity_$1_on_update(entity_t *entity, float dt);" >> $HEADER_IMPL
    echo "void entity_$1_on_render(entity_t *entity);" >> $HEADER_IMPL
}

function create_entity_sources()
{
    local FOLDER="src/entities/$1"

    mkdir -p $FOLDER

    # New
    local NEW="$FOLDER/entity_$1_new.c"
    touch $NEW
    create_epitech_header $NEW
    echo -e "\n#include \"entities/$1_impl.h\"" >> $NEW
    echo -e "\nentity_t *entity_$1_new(void)" >> $NEW
    echo "{" >> $NEW
    echo "    entity_t *entity = entity_new(sizeof(entity_$1_t));" >> $NEW
    echo -e "\n    if (entity == NULL)" >> $NEW
    echo "        return NULL;" >> $NEW
    echo "    entity_bind_on_attach(entity, entity_$1_on_attach);" >> $NEW
    echo "    entity_bind_on_detach(entity, entity_$1_on_detach);" >> $NEW
    echo "    entity_bind_on_event(entity, entity_$1_on_event);" >> $NEW
    echo "    entity_bind_on_update(entity, entity_$1_on_update);" >> $NEW
    echo "    entity_bind_on_render(entity, entity_$1_on_render);" >> $NEW
    echo "    return entity;" >> $NEW
    echo "}" >> $NEW

    # On attach
    local ON_ATTACH="$FOLDER/entity_$1_on_attach.c"
    touch $ON_ATTACH
    create_epitech_header $ON_ATTACH
    echo -e "\n#include \"entities/$1_impl.h\"" >> $ON_ATTACH
    echo -e "\nbool entity_$1_on_attach(entity_t *entity)" >> $ON_ATTACH
    echo "{" >> $ON_ATTACH
    echo "    return true;" >> $ON_ATTACH
    echo "}" >> $ON_ATTACH

    # On detach
    local ON_DETACH="$FOLDER/entity_$1_on_detach.c"
    touch $ON_DETACH
    create_epitech_header $ON_DETACH
    echo -e "\n#include \"entities/$1_impl.h\"" >> $ON_DETACH
    echo -e "\nvoid entity_$1_on_detach(entity_t *entity)" >> $ON_DETACH
    echo "{" >> $ON_DETACH
    echo "}" >> $ON_DETACH

    # On event
    local ON_EVENT="$FOLDER/entity_$1_on_event.c"
    touch $ON_EVENT
    create_epitech_header $ON_EVENT
    echo -e "\n#include \"entities/$1_impl.h\"" >> $ON_EVENT
    echo -e "\nbool entity_$1_on_event(entity_t *entity, sfEvent *event)" >> $ON_EVENT
    echo "{" >> $ON_EVENT
    echo "    return true;" >> $ON_EVENT
    echo "}" >> $ON_EVENT

    # On update
    local ON_UPDATE="$FOLDER/entity_$1_on_update.c"
    touch $ON_UPDATE
    create_epitech_header $ON_UPDATE
    echo -e "\n#include \"entities/$1_impl.h\"" >> $ON_UPDATE
    echo -e "\nbool entity_$1_on_update(entity_t *entity, float dt)" >> $ON_UPDATE
    echo "{" >> $ON_UPDATE
    echo "    return true;" >> $ON_UPDATE
    echo "}" >> $ON_UPDATE

    # On render
    local ON_RENDER="$FOLDER/entity_$1_on_render.c"
    touch $ON_RENDER
    create_epitech_header $ON_RENDER
    echo -e "\n#include \"entities/$1_impl.h\"" >> $ON_RENDER
    echo -e "\nvoid entity_$1_on_render(entity_t *entity)" >> $ON_RENDER
    echo "{" >> $ON_RENDER
    echo "}" >> $ON_RENDER
}

function create_entity()
{
    create_entity_headers $1
    create_entity_sources $1
}

# Main
if [ "$#" -ne 2 ] || ( [ "$1" != "layer" ] && [ "$1" != "entity" ] ); then
    >&2 echo "Usage: $0 <layer|entity> <name>"
    exit 1
fi

[ "$1" == "layer" ] && create_layer $2
[ "$1" == "entity" ] && create_entity $2
