//
//  unique_test.hpp
//  
//
//  Created by Gregorio Litenstein Goldzweig on 1/14/18.
//

#ifndef unique_test_hpp
#define unique_test_hpp

#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <limits>
#include <stdio.h>
#include <vector>

static inline double getNaN() { return std::numeric_limits<double>::quiet_NaN(); }

struct Note {
    Note();
    double begin, ///< begin time
    end; ///< end time
    /// which players sung well
    /// note type
    enum Type { FREESTYLE = 'F', NORMAL = ':', GOLDEN = '*', SLIDE = '+', SLEEP = '-',
        TAP = '1', HOLDBEGIN = '2', HOLDEND = '3', ROLL = '4', MINE = 'M', LIFT = 'L'} type;
    int note; ///< MIDI pitch of the note (at the end for slide notes)
    static std::string str_type(Type type) {
        switch (type) {
            case FREESTYLE: return "F";
            case NORMAL: return ":";
            case GOLDEN: return "*";
            case SLIDE: return "+";
            case SLEEP: return "-";
            case TAP: return "1";
            case HOLDBEGIN: return "2";
            case HOLDEND: return "3";
            case ROLL: return "4";
            case MINE: return "M";
            case LIFT: return "L";
            default: return "Unknown";
        }
    }
    std::string syllable;
    static bool ltBegin(Note const& a, Note const& b) {
        if (a.begin == b.begin) {
            if (a.type == Note::SLEEP) return true;
            if (b.type == Note::SLEEP) return false;
        }
        return a.begin < b.begin;
    }
    static bool equal(Note const& a, Note const& b) {
        if (a.type == Note::SLEEP) return (a.type == b.type);
        return (a.begin == b.begin && a.end == b.end && a.note == b.note && a.type == b.type);
    }
};
typedef std::vector<Note> Notes;

#endif /* unique_test_hpp */
