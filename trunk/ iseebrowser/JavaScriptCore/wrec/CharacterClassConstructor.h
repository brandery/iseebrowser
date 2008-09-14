/*
 * Copyright (C) 2008 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
 */

#ifndef CharacterClassConstructor_h
#define CharacterClassConstructor_h

#if ENABLE(WREC)

#include "ustring.h"

namespace JSC {

    struct CharacterClassRange {
        UChar begin;
        UChar end;
    };

    struct CharacterClass {
        const UChar* matches;
        unsigned numMatches;

        const CharacterClassRange* ranges;
        unsigned numRanges;

        const UChar* matchesUnicode;
        unsigned numMatchesUnicode;

        const CharacterClassRange* rangesUnicode;
        unsigned numRangesUnicode;
    };

    CharacterClass& getCharacterClassNewline();
    CharacterClass& getCharacterClassDigits();
    CharacterClass& getCharacterClassSpaces();
    CharacterClass& getCharacterClassWordchar();
    CharacterClass& getCharacterClassNondigits();
    CharacterClass& getCharacterClassNonspaces();
    CharacterClass& getCharacterClassNonwordchar();

    class CharacterClassConstructor {
    public:
        CharacterClassConstructor(bool isCaseInsensitive)
            : m_charBuffer(-1)
            , m_isPendingDash(false)
            , m_isCaseInsensitive(isCaseInsensitive)
            , m_isUpsideDown(false)
        {
        }

        void flush();
        void put(UChar ch);
        void append(CharacterClass& other);

        bool isUpsideDown() { return m_isUpsideDown; }

        ALWAYS_INLINE CharacterClass charClass()
        {
            CharacterClass newCharClass = {
                m_matches.begin(), m_matches.size(),
                m_ranges.begin(), m_ranges.size(),
                m_matchesUnicode.begin(), m_matchesUnicode.size(),
                m_rangesUnicode.begin(), m_rangesUnicode.size(),
            };

            return newCharClass;
        }

    private:
        void addSorted(Vector<UChar>& matches, UChar ch);
        void addSortedRange(Vector<CharacterClassRange>& ranges, UChar lo, UChar hi);

        int m_charBuffer;
        bool m_isPendingDash;
        bool m_isCaseInsensitive;
        bool m_isUpsideDown;

        Vector<UChar> m_matches;
        Vector<CharacterClassRange> m_ranges;
        Vector<UChar> m_matchesUnicode;
        Vector<CharacterClassRange> m_rangesUnicode;
    };

}

#endif // ENABLE(WREC)

#endif // CharacterClassConstructor_h
