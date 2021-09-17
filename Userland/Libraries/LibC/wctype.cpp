/*
 * Copyright (c) 2021, the SerenityOS developers
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <AK/Format.h>
#include <string.h>
#include <wctype.h>

enum {
    WCTYPE_INVALID = 0,
    WCTYPE_ALNUM,
    WCTYPE_ALPHA,
    WCTYPE_BLANK,
    WCTYPE_CNTRL,
    WCTYPE_DIGIT,
    WCTYPE_GRAPH,
    WCTYPE_LOWER,
    WCTYPE_PRINT,
    WCTYPE_PUNCT,
    WCTYPE_SPACE,
    WCTYPE_UPPER,
    WCTYPE_XDIGIT,
};

enum {
    WCTRANS_INVALID = 0,
    WCTRANS_TOLOWER,
    WCTRANS_TOUPPER,
};

extern "C" {

int iswalnum(wint_t wc)
{
    return __inline_isalnum(wc);
}

int iswalpha(wint_t wc)
{
    return __inline_isalpha(wc);
}

int iswcntrl(wint_t wc)
{
    return __inline_iscntrl(wc);
}

int iswdigit(wint_t wc)
{
    return __inline_isdigit(wc);
}

int iswxdigit(wint_t wc)
{
    return __inline_isxdigit(wc);
}

int iswspace(wint_t wc)
{
    return __inline_isspace(wc);
}

int iswpunct(wint_t wc)
{
    return __inline_ispunct(wc);
}

int iswprint(wint_t wc)
{
    return __inline_isprint(wc);
}

int iswgraph(wint_t wc)
{
    return __inline_isgraph(wc);
}

int iswlower(wint_t wc)
{
    return __inline_islower(wc);
}

int iswupper(wint_t wc)
{
    return __inline_isupper(wc);
}

int iswblank(wint_t wc)
{
    return __inline_isblank(wc);
}

int iswctype(wint_t, wctype_t)
{
    dbgln("FIXME: Implement iswctype()");
    TODO();
}

wctype_t wctype(const char* property)
{
    if (strcmp(property, "alnum") == 0)
        return WCTYPE_ALNUM;

    if (strcmp(property, "alpha") == 0)
        return WCTYPE_ALPHA;

    if (strcmp(property, "blank") == 0)
        return WCTYPE_BLANK;

    if (strcmp(property, "cntrl") == 0)
        return WCTYPE_CNTRL;

    if (strcmp(property, "digit") == 0)
        return WCTYPE_DIGIT;

    if (strcmp(property, "graph") == 0)
        return WCTYPE_GRAPH;

    if (strcmp(property, "lower") == 0)
        return WCTYPE_LOWER;

    if (strcmp(property, "print") == 0)
        return WCTYPE_PRINT;

    if (strcmp(property, "punct") == 0)
        return WCTYPE_PUNCT;

    if (strcmp(property, "space") == 0)
        return WCTYPE_SPACE;

    if (strcmp(property, "upper") == 0)
        return WCTYPE_UPPER;

    if (strcmp(property, "xdigit") == 0)
        return WCTYPE_XDIGIT;

    return WCTYPE_INVALID;
}

wint_t towlower(wint_t wc)
{
    return __inline_tolower(wc);
}

wint_t towupper(wint_t wc)
{
    return __inline_toupper(wc);
}

wint_t towctrans(wint_t, wctrans_t)
{
    dbgln("FIXME: Implement towctrans()");
    TODO();
}

wctrans_t wctrans(const char* charclass)
{
    if (strcmp(charclass, "tolower") == 0)
        return WCTRANS_TOLOWER;

    if (strcmp(charclass, "toupper") == 0)
        return WCTRANS_TOUPPER;

    return WCTRANS_INVALID;
}
}
