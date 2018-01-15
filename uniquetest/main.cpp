//
//  unique_test.cpp
//
//
//  Created by Gregorio Litenstein Goldzweig on 1/14/18.
//

#include "unique_test.hpp"

Note::Note(): begin(getNaN()), end(getNaN()), type(NORMAL), note() {}

int main() {
    Notes s1, s2, merged;
    srand(time(NULL));
    int rnum;
    Note n = Note();
    for (unsigned i = 0; i <= 70; i++) {
        n.begin = i;
        n.note = i;
        rnum = rand()%10;
        n.end = i + rnum;
        std::clog << "Generated random number: " << rnum << std::endl;
        n.syllable = (rnum > 5) ? "test" : "test2";
        n.type = (rnum > 5) ? Note::GOLDEN : Note::NORMAL;
        s1.push_back(n);
    }
    for (unsigned i = 0; i <= 70; i++) {
        n.begin = i;
        n.note = i;
        rnum = rand()%10;
        n.end = i + rnum;
        std::clog << "Generated random number: " << rnum << std::endl;
        n.syllable = (rnum > 5) ? "test" : "test2";
        n.type = (rnum > 5) ? Note::GOLDEN : Note::NORMAL;
        s2.push_back(n);
    }
    std::clog << "Last note of s1..." << " (" << s1.back().syllable << ")" << ", begin: " << s1.back().begin << ", end: " << s1.back().end << ", type: " << Note::str_type(s1.back().type) << std::endl;
    std::clog << "Last note of s2..." << " (" << s2.back().syllable << ")" << ", begin: " << s2.back().begin << ", end: " << s2.back().end << ", type: " << Note::str_type(s2.back().type) << std::endl;
    std::merge(s1.begin(), s1.end(), s2.begin(), s2.end(), std::back_inserter(merged), Note::ltBegin);
    
    auto test = merged.rbegin();
    std::clog << "Last note of test..." << " (" << test->syllable << ")" << ", begin: " << test->begin << ", end: " << test->end << ", type: " << Note::str_type(test->type) << std::endl;
    ++test;
    std::clog << "Previous to Last note of test..." << " (" << test->syllable << ")" << ", begin: " << test->begin << ", end: " << test->end << ", type: " << Note::str_type(test->type) << std::endl;
    std::unique(merged.begin(), merged.end(), Note::equal);
    test = merged.rbegin();
    std::clog << "Last note of test... (after unique)" << " (" << test->syllable << ")" << ", begin: " << test->begin << ", end: " << test->end << ", type: " << Note::str_type(test->type) << std::endl;
    for (size_t pointer = merged.size(); pointer >= 100; --pointer) {
    ++test;
        std::clog << "Test note at position: " << pointer << "(after unique)..." << " (" << test->syllable << ")" << ", begin: " << test->begin << ", end: " << test->end << ", type: " << Note::str_type(test->type) << std::endl;
    }
}




