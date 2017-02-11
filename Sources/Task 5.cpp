#include<iostream>
#include<string.h>
#include"H:\ContestProgramming\Schedule Vehicle\Headers\LineSchedule.hpp"

using namespace std;

Stop s1("Duisburg Rheindeich\t\t",0),s2("Lilienthalstrasse\t\t",1),s3("Javastrasse\t\t",3),
    s4("Kartholische Kirche\t\t",4),s5("Am Schluetershof\t\t",5),s6("Tierheim\t\t",6),
    s7("Sperrschleuse\t\t",8),s8("Landesarchiv NRW\t\t",10),s9("Schwanentor\t\t",12),
    s10("Friedrich-Wilhelm-Platz\t\t",15),s11("Lehmbruck-Meuseum\t\t",17),s12("Tonhallenstrasse\t\t",18),
    s13("Duisburg Hbf\t\t",20),s14("Duisburg Hbf Osteingang\t\t",22), s15("Blumenstrasse\t\t",23),
    s16("Bismarckstrasse\t\t",25),s17("Kammerstrasse\t\t",27),s18("Lenaustrasse\t\t",28),
    s19("Nettelbeckstrasse\t\t",29),s20("Buergerstrasse\t\t",30),s21("Universitaet\t\t",31),
    s22("Uni-nord\t\t",32);

Departuret n1(4,18),n2(4,48),n3(5,18),n4(5,48),n5(6,3),n6(6,18),n7(6,33),n8(6,48),n9(7,3),n10(7,18),
    n11(7,33),n12(7,48),n13(8,3),n14(8,18),n15(8,33),n16(8,48),n17(9,3),n18(9,18),n19(9,33),n20(9,48),
    n21(10,3),n22(10,18),n23(10,33),n24(10,48),n25(11,3),n26(11,18),n27(11,33),n28(11,48),n29(12,03),n30(12,18),
    n31(12,33),n32(12,48),n33(13,3),n34(13,18),n35(13,33),n36(13,48),n37(14,3),n38(14,18),n39(14,33),n40(14,48),
    n41(15,3),n42(15,18),n43(15,33),n44(15,48),n45(16,3),n46(16,18),n47(16,33),n48(16,48),n49(17,3),n50(17,18),
    n51(17,33),n52(17,48),n53(18,03),n54(18,18),n55(18,33),n56(18,48),n57(19,03),n58(19,29),n59(19,59),n60(20,29),
    n61(20,59),n62(21,29),n63(21,59),n64(22,29),n65(22,59),n66(23,29);

Departuret m1(4,29),m2(4,59),m3(5,29),m4(5,59),m5(6,29),m6(6,48),m7(7,18),m8(7,48),
    m9(8,18),m10(8,48),m11(9,18),m12(9,48),m13(10,18),m14(10,48),m15(11,18),m16(11,48),
    m17(12,18),m18(12,48),m19(13,18),m20(13,48),m21(14,18),m22(14,48),m23(15,18),m24(15,48),
    m25(16,29),m26(16,59),m27(17,29),m28(17,59),m29(18,29),m30(18,59),m31(19,29),m32(19,59),
    m33(20,29),m34(20,59),m35(21,29),m36(21,59),m37(22,29),m38(22,59),m39(23,29);

void routedatawrite();
void depTimewrite();

int main(){

    Line VRR[1000];
    Departuret *mm, *nn;
    mm = &m1;
    nn = &n1;
    Time t();
    routedatawrite();
    depTimewrite();

    VRR[933].seT_no(933);
    VRR[933].seT_from(&s1);
    VRR[933].set_depTime(1,nn);
    VRR[933].set_depTime(2,mm);

    Line *line;
    line = &VRR[933];
    LineSchedule lineSchedule(line);
    lineSchedule.print_workUnits();
    lineSchedule.print_statistics();
}

void depTimewrite()
{
    n1.set_next(&n2);
    n2.set_next(&n3);
    n3.set_next(&n4);
    n4.set_next(&n5);
    n5.set_next(&n6);
    n6.set_next(&n7);
    n7.set_next(&n8);
    n8.set_next(&n9);
    n9.set_next(&n10);
    n10.set_next(&n11);
    n11.set_next(&n12);
    n12.set_next(&n13);
    n13.set_next(&n14);
    n14.set_next(&n15);
    n15.set_next(&n16);
    n16.set_next(&n17);
    n17.set_next(&n18);
    n18.set_next(&n19);
    n19.set_next(&n20);
    n20.set_next(&n21);
    n21.set_next(&n22);
    n22.set_next(&n23);
    n23.set_next(&n24);
    n24.set_next(&n25);
    n25.set_next(&n26);
    n26.set_next(&n27);
    n27.set_next(&n28);
    n28.set_next(&n29);
    n29.set_next(&n30);
    n30.set_next(&n31);
    n31.set_next(&n32);
    n32.set_next(&n33);
    n33.set_next(&n34);
    n34.set_next(&n35);
    n35.set_next(&n36);
    n36.set_next(&n37);
    n37.set_next(&n38);
    n38.set_next(&n39);
    n39.set_next(&n40);
    n40.set_next(&n41);
    n41.set_next(&n42);
    n42.set_next(&n43);
    n43.set_next(&n44);
    n44.set_next(&n45);
    n45.set_next(&n46);
    n46.set_next(&n47);
    n47.set_next(&n48);
    n48.set_next(&n49);
    n49.set_next(&n50);
    n50.set_next(&n51);
    n51.set_next(&n52);
    n52.set_next(&n53);
    n53.set_next(&n54);
    n54.set_next(&n55);
    n55.set_next(&n56);
    n56.set_next(&n57);
    n57.set_next(&n58);
    n58.set_next(&n59);
    n59.set_next(&n60);
    n60.set_next(&n61);
    n61.set_next(&n62);
    n62.set_next(&n63);
    n63.set_next(&n64);
    n64.set_next(&n65);
    n65.set_next(&n66);

    m1.set_next(&m2);
    m2.set_next(&m3);
    m3.set_next(&m4);
    m4.set_next(&m5);
    m5.set_next(&m6);
    m6.set_next(&m7);
    m7.set_next(&m8);
    m8.set_next(&m9);
    m9.set_next(&m10);
    m10.set_next(&m11);
    m11.set_next(&m12);
    m12.set_next(&m13);
    m13.set_next(&m14);
    m14.set_next(&m15);
    m15.set_next(&m16);
    m16.set_next(&m17);
    m17.set_next(&m18);
    m18.set_next(&m19);
    m19.set_next(&m20);
    m20.set_next(&m21);
    m21.set_next(&m22);
    m22.set_next(&m23);
    m23.set_next(&m24);
    m24.set_next(&m25);
    m25.set_next(&m26);
    m26.set_next(&m27);
    m27.set_next(&m28);
    m28.set_next(&m29);
    m29.set_next(&m30);
    m30.set_next(&m31);
    m31.set_next(&m32);
    m32.set_next(&m33);
    m33.set_next(&m34);
    m34.set_next(&m35);
    m35.set_next(&m36);
    m36.set_next(&m37);
    m37.set_next(&m38);
    m38.set_next(&m39);

}
void routedatawrite()
{
    s1.set_next(&s2);
    s2.set_next(&s3);
    s3.set_next(&s4);
    s4.set_next(&s5);
    s5.set_next(&s6);
    s6.set_next(&s7);
    s7.set_next(&s8);
    s8.set_next(&s9);
    s9.set_next(&s10);
    s10.set_next(&s11);
    s11.set_next(&s12);
    s12.set_next(&s13);
    s13.set_next(&s14);
    s14.set_next(&s15);
    s15.set_next(&s16);
    s16.set_next(&s17);
    s17.set_next(&s18);
    s18.set_next(&s19);
    s19.set_next(&s20);
    s20.set_next(&s21);
    s21.set_next(&s22);
}
