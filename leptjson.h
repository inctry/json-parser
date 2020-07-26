//
// Created by Inctry on 2020/7/25.
//

#ifndef JSON_PARSER_LEPTJSON_H
#define JSON_PARSER_LEPTJSON_H
#include <stdio.h>
#include <stddef.h>
#include <assert.h>

typedef enum {
    LEPT_NULL, LEPT_FALSE, LEPT_TRUE, LEPT_NUMBER, LEPT_STRING, LEPT_ARRAY, LEPT_OBJECT
}lept_type;
enum {
    LEPT_PARSE_OK = 0,
    LEPT_PARSE_EXPECT_VALUE,
    LEPT_PARSE_INVALID_VALUE,
    LEPT_PARSE_ROOT_NOT_SINGULAR
};
typedef struct {
    lept_type type;
}lept_value;

typedef struct {
    const char *json;
}lept_context;

int lept_parse(lept_value *v, const char *json);
lept_type lept_get_type(const lept_value *v);

static void lept_parse_whitespace(lept_context *c);
static int lept_parse_value(lept_context *c, lept_value *v);
static int lept_parse_null(lept_context *c, lept_value *v);
static int lept_parse_true(lept_context *c, lept_value *v);
static int lept_parse_false(lept_context *c, lept_value *v);

#endif //JSON_PARSER_LEPTJSON_H
