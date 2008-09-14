#ifndef QHARFBUZZ_H
#define QHARFBUZZ_H

#include "harfbuzz-shaper.h"
#include "qstring.h"

QT_BEGIN_NAMESPACE

// temporary forward until all the textengine code has been moved to QtCore
Q_CORE_EXPORT void qGetCharAttributes(const HB_UChar16 *string, hb_uint32 stringLength,
                                      const HB_ScriptItem *items, hb_uint32 numItems,
                                      HB_CharAttributes *attributes);

Q_CORE_EXPORT HB_Bool qShapeItem(HB_ShaperItem *item);

#if 0
// ### temporary
Q_CORE_EXPORT HB_Face qHBNewFace(void *font, HB_GetFontTableFunc tableFunc);
Q_CORE_EXPORT void qHBFreeFace(HB_Face);

Q_DECLARE_TYPEINFO(HB_GlyphAttributes, Q_PRIMITIVE_TYPE);
Q_DECLARE_TYPEINFO(HB_FixedPoint, Q_PRIMITIVE_TYPE);
#endif

QT_END_NAMESPACE

#endif // QHARFBUZZ_H
