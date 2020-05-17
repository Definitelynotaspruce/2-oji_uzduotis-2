#include <gtest/gtest.h>
#include "../headeriai/Studentas.h"

namespace {
    TEST(test_studentas, test_getVardas)
    {
        Studentas s("Algis", "Ramanauskas");
        ASSERT_EQ(s.getVardas(), "Algis");
    }

    TEST(test_studentas, test_getPavarde)
    {
        Studentas s("Algis", "Ramanauskas");
        ASSERT_EQ(s.getPavarde(), "Ramanauskas");
    }

    TEST(test_studentas, test_getVardasPavarde)
    {
        Studentas s("Algis", "Ramanauskas");
        ASSERT_EQ(s.getVardasPavarde(), "Algis Ramanauskas");
    }

    TEST(test_studentas, test_getVidurkis)
    {
        Studentas s("Al Ra 10 10 10 10 10 4");
        ASSERT_EQ(s.getVidurkis(), 10);
    }

    TEST(test_studentas, test_getMediana)
    {
        Studentas s("Al Ra 4 2 3 1 5");
        ASSERT_EQ(s.getMediana(), 2.5);
    }

    TEST(test_studentas, test_Egzaminas)
    {
        Studentas s("Al Ra 10 10 10 10 7");
        ASSERT_EQ(s.getEgzaminas(), 7);
    }

    TEST(test_studentas, test_Galutinis)
    {
        Studentas s("Al Ra 10 10 10 10 10");
        ASSERT_EQ(s.getGalutinis(), 10);
    }

    TEST(test_studentas, test_Pliuso_Operatoriaus_Galutinis)
    {
        Studentas s1("Al Ra 10 10");
        Studentas s2("Al Ra 1 1");
        Studentas s3 = s1 + s2;
        ASSERT_EQ(s3.getGalutinis(), 8.2);
    }

    TEST(test_studentas, test_Pliuso_Operatoriaus_Vidurkis)
    {
        Studentas s1("Al Ra 10 10");
        Studentas s2("Al Ra 1 1");
        Studentas s3 = s1 + s2;
        ASSERT_EQ(s3.getVidurkis(), 5.5);
    }

    TEST(test_studentas, test_Daugiau_Maziau_Operatorius)
    {
        Studentas s1("Al Ra 10 10");
        Studentas s2("Al Ra 1 1");
        ASSERT_EQ(s1 > s2, true);
    }    
    
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}


