#include<algorithm> 
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

const double AUDUSD[200] = {
0.692750,
0.692770,
0.692800,
0.693200,
0.693040,
0.693040,
0.693070,
0.693060,
0.693000,
0.692990,
0.693000,
0.693030,
0.693050,
0.693090,
0.693110,
0.693060,
0.693160,
0.693160,
0.693140,
0.693120,
0.693040,
0.693050,
0.693010,
0.692910,
0.692910,
0.692910,
0.692900,
0.692900,
0.693070,
0.693130,
0.693110,
0.693030,
0.693180,
0.693250,
0.693190,
0.693270,
0.693270,
0.693280,
0.693290,
0.693290,
0.693300,
0.693290,
0.693290,
0.693170,
0.693170,
0.693240,
0.693140,
0.693160,
0.693100,
0.693100,
0.693090,
0.693100,
0.693060,
0.693070,
0.693060,
0.693140,
0.693160,
0.693260,
0.693240,
0.693280,
0.693210,
0.693210,
0.693180,
0.693180,
0.693150,
0.693080,
0.693240,
0.693140,
0.693100,
0.693150,
0.693170,
0.693030,
0.693140,
0.693140,
0.693040,
0.693140,
0.693140,
0.693140,
0.693070,
0.693070,
0.693040,
0.693030,
0.693060,
0.692970,
0.693090,
0.693090,
0.693100,
0.693060,
0.693040,
0.693040,
0.693080,
0.693100,
0.693150,
0.693160,
0.693160,
0.693160,
0.693150,
0.693160,
0.693100,
0.693090,
0.693080,
0.693080,
0.693100,
0.693160,
0.693160,
0.693160,
0.693170,
0.693260,
0.693260,
0.693270,
0.693260,
0.693370,
0.693370,
0.693370,
0.693290,
0.693380,
0.693370,
0.693280,
0.693260,
0.693270,
0.693180,
0.693270,
0.693120,
0.693080,
0.693050,
0.693060,
0.693060,
0.692960,
0.692960,
0.692960,
0.692960,
0.693070,
0.692970,
0.693050,
0.693050,
0.693060,
0.692960,
0.692990,
0.693090,
0.693060,
0.693070,
0.693080,
0.693060,
0.693110,
0.693100,
0.693090,
0.693090,
0.693050,
0.693040,
0.693040,
0.693060,
0.693060,
0.693010,
0.693080,
0.693090,
0.693090,
0.693050,
0.693060,
0.693060,
0.693090,
0.693090,
0.693160,
0.693100,
0.693080,
0.693160,
0.693090,
0.693080,
0.693050,
0.693050,
0.693020,
0.693000,
0.693040,
0.692970,
0.692960,
0.692990,
0.692950,
0.692890,
0.692870,
0.692840,
0.692740,
0.692760,
0.692880,
0.692990,
0.693170,
0.693250,
0.693380,
0.693440,
0.693670,
0.693770,
0.693630,
0.693670,
0.693980,
0.694000,
0.693850,
0.693750,
0.693670,
0.693740,
0.693860,
0.693890,
0.694190};

const double EURAUD[200] = {

1.611030,
1.610850,
1.610960,
1.610040,
1.610420,
1.610230,
1.610150,
1.610300,
1.609840,
1.609840,
1.610290,
1.610350,
1.610410,
1.610340,
1.609890,
1.609880,
1.609990,
1.610340,
1.609930,
1.610340,
1.610150,
1.610160,
1.610160,
1.610270,
1.610170,
1.610180,
1.610030,
1.610070,
1.609610,
1.610530,
1.610350,
1.610630,
1.610690,
1.610450,
1.610470,
1.610360,
1.610380,
1.610550,
1.610520,
1.610540,
1.610510,
1.610620,
1.610600,
1.610690,
1.610670,
1.610610,
1.610870,
1.610790,
1.610940,
1.610850,
1.610900,
1.610910,
1.610910,
1.610950,
1.610880,
1.610800,
1.610580,
1.610610,
1.610680,
1.610800,
1.611110,
1.611210,
1.611310,
1.611300,
1.611460,
1.611600,
1.611410,
1.611560,
1.611640,
1.611520,
1.611460,
1.611710,
1.611640,
1.611570,
1.611780,
1.611650,
1.611650,
1.611570,
1.611780,
1.611700,
1.611720,
1.611710,
1.611600,
1.611700,
1.611630,
1.611590,
1.611570,
1.611540,
1.611530,
1.611420,
1.611390,
1.611410,
1.611190,
1.611240,
1.611200,
1.611320,
1.611400,
1.611380,
1.611510,
1.611790,
1.611740,
1.611820,
1.611750,
1.611440,
1.611360,
1.611440,
1.611430,
1.611400,
1.611470,
1.611440,
1.611520,
1.611310,
1.611270,
1.611230,
1.611370,
1.611190,
1.611110,
1.611280,
1.611220,
1.611310,
1.611470,
1.611360,
1.611610,
1.611680,
1.611790,
1.611760,
1.611680,
1.611850,
1.612070,
1.612030,
1.612000,
1.611890,
1.611960,
1.611830,
1.611810,
1.611810,
1.611930,
1.611930,
1.611770,
1.611800,
1.611880,
1.611860,
1.611860,
1.611790,
1.611800,
1.611720,
1.611680,
1.611810,
1.611790,
1.611790,
1.611680,
1.611680,
1.611810,
1.611770,
1.611780,
1.611790,
1.611880,
1.611800,
1.611760,
1.611780,
1.611810,
1.611680,
1.611880,
1.611880,
1.611790,
1.612010,
1.612000,
1.611970,
1.611930,
1.612090,
1.612080,
1.612020,
1.612150,
1.612220,
1.612050,
1.612200,
1.612350,
1.612430,
1.612540,
1.612660,
1.612610,
1.612750,
1.612350,
1.611990,
1.611780,
1.611650,
1.611520,
1.611010,
1.610830,
1.611270,
1.611250,
1.610610,
1.610560,
1.610850,
1.610960,
1.611070,
1.610950,
1.610710,
1.610700,
1.610020};

const double EURCHF[200] = {
1.117500,
1.117500,
1.117740,
1.117160,
1.117840,
1.117740,
1.117250,
1.117260,
1.117310,
1.117290,
1.117740,
1.117270,
1.117350,
1.117340,
1.117330,
1.117740,
1.117310,
1.117290,
1.117130,
1.117120,
1.117740,
1.117610,
1.117570,
1.117590,
1.117610,
1.117710,
1.117650,
1.117340,
1.117600,
1.117680,
1.117630,
1.117590,
1.117700,
1.117800,
1.117750,
1.117700,
1.117750,
1.117680,
1.117660,
1.117610,
1.117820,
1.117830,
1.117800,
1.117780,
1.117770,
1.117800,
1.117940,
1.118420,
1.118100,
1.118090,
1.117550,
1.117630,
1.117670,
1.117660,
1.117410,
1.117370,
1.117370,
1.117240,
1.117330,
1.117310,
1.117310,
1.117260,
1.117290,
1.117300,
1.117390,
1.117340,
1.117350,
1.117410,
1.117390,
1.117350,
1.117340,
1.117310,
1.117280,
1.117170,
1.117040,
1.116950,
1.117090,
1.117050,
1.117050,
1.117030,
1.117120,
1.117180,
1.117330,
1.117270,
1.117260,
1.117290,
1.117250,
1.117110,
1.117070,
1.117020,
1.117020,
1.116920,
1.116910,
1.116970,
1.117010,
1.116960,
1.116910,
1.116910,
1.116900,
1.116900,
1.116910,
1.116910,
1.116930,
1.116960,
1.116940,
1.116930,
1.116910,
1.116910,
1.116950,
1.116990,
1.116930,
1.116940,
1.116970,
1.116980,
1.116960,
1.116910,
1.116920,
1.116930,
1.116940,
1.116890,
1.116900,
1.116890,
1.116900,
1.116910,
1.116900,
1.116920,
1.116910,
1.116920,
1.116900,
1.116910,
1.116890,
1.116920,
1.116940,
1.116910,
1.116930,
1.116890,
1.116910,
1.116850,
1.116820,
1.116870,
1.116850,
1.116800,
1.116820,
1.116820,
1.116740,
1.116770,
1.116730,
1.116740,
1.116740,
1.116770,
1.116740,
1.116710,
1.116720,
1.116750,
1.116770,
1.116760,
1.116770,
1.116800,
1.116820,
1.116890,
1.116870,
1.116830,
1.116810,
1.116850,
1.116880,
1.116880,
1.116810,
1.116870,
1.116860,
1.116910,
1.116940,
1.117020,
1.116870,
1.117150,
1.117010,
1.117130,
1.117110,
1.117160,
1.117210,
1.117090,
1.117120,
1.117180,
1.117240,
1.117370,
1.117370,
1.117310,
1.117200,
1.117150,
1.117180,
1.117240,
1.117240,
1.117260,
1.117260,
1.117270,
1.117270,
1.117310,
1.117300,
1.117190,
1.117180,
1.117150};

const double CHFJPY[200] = {
108.0710,
108.0340,
108.0800,
108.0200,
108.0190,
108.0860,
108.0200,
108.0960,
108.0860,
108.0190,
108.0220,
108.0550,
108.0900,
108.0560,
108.0550,
108.0650,
108.1200,
108.0890,
108.0950,
108.0920,
108.0880,
108.0360,
108.0740,
108.0800,
108.0670,
108.1090,
108.0800,
108.0770,
108.1050,
108.1160,
108.1040,
108.0830,
108.0880,
108.0910,
108.1270,
108.1160,
108.1150,
108.1200,
108.1210,
108.1190,
108.1170,
108.1190,
108.1550,
108.1450,
108.1470,
108.1560,
108.1490,
108.1530,
108.1390,
108.1020,
108.1290,
108.1650,
108.1440,
108.1270,
108.1670,
108.1770,
108.1780,
108.1990,
108.2130,
108.1870,
108.1800,
108.1900,
108.1950,
108.1910,
108.2120,
108.2200,
108.2140,
108.2290,
108.2240,
108.2220,
108.2230,
108.2070,
108.2020,
108.1980,
108.1990,
108.1910,
108.1920,
108.2050,
108.2040,
108.2010,
108.2020,
108.1990,
108.2040,
108.1980,
108.2020,
108.1720,
108.1670,
108.1650,
108.1670,
108.1670,
108.1940,
108.1920,
108.1980,
108.1940,
108.1920,
108.1920,
108.1950,
108.1950,
108.1960,
108.2110,
108.2070,
108.2100,
108.2030,
108.2080,
108.2130,
108.2130,
108.2210,
108.2130,
108.2200,
108.2070,
108.2120,
108.2080,
108.2080,
108.2080,
108.2510,
108.2380,
108.2540,
108.2540,
108.2550,
108.2560,
108.2590,
108.2640,
108.2690,
108.2740,
108.2710,
108.2780,
108.2760,
108.2920,
108.2980,
108.2910,
108.2870,
108.2950,
108.2910,
108.2940,
108.2880,
108.2920,
108.2810,
108.2950,
108.2800,
108.2820,
108.2690,
108.2730,
108.2770,
108.2820,
108.2890,
108.2810,
108.2830,
108.2740,
108.2790,
108.2920,
108.2860,
108.2920,
108.2970,
108.2850,
108.2870,
108.2940,
108.2870,
108.2870,
108.2810,
108.2700,
108.2610,
108.2600,
108.2560,
108.2510,
108.2490,
108.2570,
108.2590,
108.2700,
108.2390,
108.2500,
108.2550,
108.2500,
108.2480,
108.2550,
108.2470,
108.2530,
108.2750,
108.2870,
108.2830,
108.2900,
108.3070,
108.2970,
108.3180,
108.3160,
108.3020,
108.3050,
108.3100,
108.2990,
108.3060,
108.2980,
108.2880,
108.2920,
108.3070,
108.3040,
108.3040,
108.3110,
108.3020,
108.3130,
108.3010,
108.2720};

const double CADJPY[200] = {
80.0650,
80.0680,
80.0630,
80.0650,
80.0720,
80.0730,
80.0830,
80.0860,
80.0860,
80.0740,
80.0740,
80.0760,
80.0750,
80.0780,
80.0790,
80.0770,
80.0820,
80.0650,
80.0920,
80.0650,
80.0660,
80.0710,
80.1160,
80.0900,
80.1010,
80.0940,
80.0920,
80.0910,
80.0820,
80.0840,
80.1000,
80.1120,
80.0840,
80.0910,
80.1120,
80.1150,
80.1020,
80.0840,
80.1000,
80.1010,
80.1070,
80.0930,
80.0990,
80.0990,
80.1010,
80.1000,
80.1000,
80.0970,
80.0960,
80.0960,
80.1130,
80.0970,
80.0960,
80.0970,
80.0990,
80.0980,
80.1010,
80.1000,
80.0980,
80.1130,
80.0780,
80.0690,
80.0650,
80.0650,
80.0650,
80.0410,
80.0340,
80.0340,
80.0440,
80.0420,
80.0550,
80.0550,
80.0530,
80.0590,
80.0520,
80.0530,
80.0580,
80.0430,
80.0370,
80.0280,
80.0170,
80.0100,
80.0160,
80.0090,
80.0070,
80.0110,
80.0080,
80.0080,
80.0100,
80.0150,
80.0280,
80.0150,
80.0050,
80.0050,
80.0050,
79.9970,
79.9990,
79.9910,
79.9880,
79.9870,
79.9760,
79.9750,
79.9850,
79.9890,
79.9910,
80.0000,
79.9850,
79.9920,
79.9830,
79.9830,
79.9940,
79.9980,
80.0090,
80.0030,
80.0090,
80.0000,
80.0040,
80.0090,
80.0050,
80.0040,
80.0340,
80.0250,
80.0360,
80.0380,
80.0350,
80.0350,
80.0380,
80.0470,
80.0470,
80.0450,
80.0410,
80.0470,
80.0420,
80.0570,
80.0620,
80.0570,
80.0540,
80.0570,
80.0530,
80.0550,
80.0540,
80.0540,
80.0440,
80.0600,
80.0500,
80.0570,
80.0430,
80.0500,
80.0540,
80.0600,
80.0620,
80.0610,
80.0630,
80.0450,
80.0450,
80.0510,
80.0480,
80.0570,
80.0650,
80.0560,
80.0510,
80.0540,
80.0530,
80.0540,
80.0480,
80.0360,
80.0300,
80.0320,
80.0370,
80.0280,
80.0290,
80.0400,
80.0410,
80.0540,
80.0250,
80.0340,
80.0390,
80.0330,
80.0350,
80.0350,
80.0360,
80.0260,
80.0510,
80.0590,
80.0710,
80.0890,
80.0890,
80.0870,
80.0950,
80.1010,
80.0850,
80.0950,
80.1070,
80.1010,
80.1000,
80.0910,
80.0870,
80.0900,
80.1060,
80.1050};

const double GBPCAD[200] = { 
1.707180,
1.707130,
1.707190,
1.707130,
1.705670,
1.706150,
1.706200,
1.706320,
1.706980,
1.706980,
1.705900,
1.706310,
1.706540,
1.706540,
1.705800,
1.705790,
1.705800,
1.706430,
1.706310,
1.706310,
1.706880,
1.706920,
1.707080,
1.707430,
1.707630,
1.707650,
1.707600,
1.707590,
1.707650,
1.707650,
1.706670,
1.707440,
1.707300,
1.707370,
1.707370,
1.707300,
1.707380,
1.707060,
1.707210,
1.707110,
1.707140,
1.707110,
1.707110,
1.707320,
1.707320,
1.707330,
1.707180,
1.707240,
1.707150,
1.707240,
1.707980,
1.708100,
1.708120,
1.708100,
1.708290,
1.708060,
1.708070,
1.708110,
1.707940,
1.707950,
1.708080,
1.708150,
1.708050,
1.708170,
1.708230,
1.708190,
1.708100,
1.708150,
1.708140,
1.708300,
1.708370,
1.708340,
1.708120,
1.708220,
1.708200,
1.708370,
1.708380,
1.708360,
1.708410,
1.708440,
1.708340,
1.708230,
1.708520,
1.708460,
1.708680,
1.708770,
1.708810,
1.708920,
1.708920,
1.708930,
1.709020,
1.709020,
1.708900,
1.708910,
1.708770,
1.708660,
1.708890,
1.708760,
1.708780,
1.708870,
1.708620,
1.708640,
1.708570,
1.708570,
1.708520,
1.708500,
1.708500,
1.708500,
1.708700,
1.708470,
1.708650,
1.708720,
1.708760,
1.708680,
1.708670,
1.708680,
1.708640,
1.708660,
1.708780,
1.708690,
1.708670,
1.708520,
1.708570,
1.708610,
1.708580,
1.708570,
1.708590,
1.708690,
1.708700,
1.708730,
1.708570,
1.708710,
1.708720,
1.708570,
1.708660,
1.708470,
1.708540,
1.708460,
1.708450,
1.708440,
1.708330,
1.708320,
1.708350,
1.708400,
1.708490,
1.708440,
1.708450,
1.708390,
1.708260,
1.708320,
1.708340,
1.708360,
1.708380,
1.708310,
1.708360,
1.708440,
1.708470,
1.708470,
1.708380,
1.708480,
1.708530,
1.708230,
1.708330,
1.708210,
1.708260,
1.708270,
1.708270,
1.708350,
1.708560,
1.708780,
1.709030,
1.709240,
1.709160,
1.708920,
1.708820,
1.708830,
1.708920,
1.708980,
1.709090,
1.709130,
1.709120,
1.709010,
1.709060,
1.709040,
1.709030,
1.708990,
1.708880,
1.708880,
1.708760,
1.708790,
1.708540,
1.708650,
1.708640,
1.708650,
1.708750,
1.708880,
1.708880,
1.708900,
1.708900,
1.709000};

const double GBPUSD[200] = {
1.262760,
1.262760,
1.262750,
1.262700,
1.262920,
1.262860,
1.262510,
1.262760,
1.262750,
1.262720,
1.262880,
1.262890,
1.262810,
1.262760,
1.262730,
1.262350,
1.262380,
1.262670,
1.262700,
1.262710,
1.262710,
1.262670,
1.262670,
1.262680,
1.262460,
1.262190,
1.262460,
1.262410,
1.262910,
1.262910,
1.262770,
1.262800,
1.262700,
1.263010,
1.263420,
1.263390,
1.263300,
1.263360,
1.263440,
1.263400,
1.262800,
1.262950,
1.263020,
1.262990,
1.263020,
1.263230,
1.263270,
1.262990,
1.263100,
1.263140,
1.263100,
1.263110,
1.263110,
1.263120,
1.263130,
1.263130,
1.263160,
1.263150,
1.263180,
1.263170,
1.263520,
1.263560,
1.263500,
1.263480,
1.263670,
1.263370,
1.263430,
1.263450,
1.263460,
1.263460,
1.263540,
1.263540,
1.263470,
1.263540,
1.263470,
1.263440,
1.263480,
1.263490,
1.263390,
1.263410,
1.263330,
1.263280,
1.263230,
1.263210,
1.263230,
1.263430,
1.263420,
1.263410,
1.263400,
1.263400,
1.263300,
1.263230,
1.263440,
1.263440,
1.263530,
1.263450,
1.263520,
1.263510,
1.263500,
1.263540,
1.263650,
1.263640,
1.263640,
1.263640,
1.263520,
1.263430,
1.263430,
1.263470,
1.263550,
1.263620,
1.263540,
1.263620,
1.263650,
1.263650,
1.263640,
1.263630,
1.263630,
1.263630,
1.263630,
1.263450,
1.263560,
1.263570,
1.263650,
1.263540,
1.263530,
1.263540,
1.263550,
1.263530,
1.263530,
1.263560,
1.263430,
1.263460,
1.263450,
1.263420,
1.263440,
1.263440,
1.263440,
1.263460,
1.263550,
1.263430,
1.263550,
1.263560,
1.263540,
1.263630,
1.263550,
1.263540,
1.263540,
1.263540,
1.263530,
1.263420,
1.263420,
1.263440,
1.263430,
1.263540,
1.263550,
1.263550,
1.263530,
1.263440,
1.263530,
1.263560,
1.263560,
1.263560,
1.263560,
1.263570,
1.263640,
1.263640,
1.263620,
1.263540,
1.263530,
1.263630,
1.263550,
1.263630,
1.263520,
1.263540,
1.263530,
1.263520,
1.263560,
1.263760,
1.263860,
1.263960,
1.264070,
1.264150,
1.263970,
1.264100,
1.264330,
1.264270,
1.264370,
1.264480,
1.264680,
1.264560,
1.264570,
1.264650,
1.264660,
1.264550,
1.264560,
1.264470,
1.264470,
1.264460,
1.264450,
1.264460};


class algotrade{
    public:
       
       int today;
       int tradeid;


       algotrade();
       void trade(int x);
       void enter_buy(int t);
       void close_buy(int id, int t); 

       vector<int> ifopen;
       vector<int> entertime;
       vector<double> entervalue;
       vector<double> volume;
       vector<int> closetime;
       vector<double> closevalue;
       vector<double> profit;


     

};

algotrade::algotrade(){



       ifopen.resize(200);
       entertime.resize(200);
       entervalue.resize(200);
       volume.resize(200);
       closetime.resize(200);
        closevalue.resize(200);
        profit.resize(200);

        tradeid=0;

}


void algotrade::trade(int x)
{

today=x;

const double ERROR= -.00005;
const double EXIT= -.002;

vector<double> tradepath;

if(GBPUSD[today]-GBPUSD[today-1]<ERROR)
{
   enter_buy(today);
}


for(int i=0;i<=tradeid; i++)
{
  int check; 
  check=ifopen[i];

   if(check==1){
      
       
/*
       for(int j=t;j<=today;j++)
           tradepath.push_backj]); 
      
*/       

       if(GBPUSD[today]-GBPUSD[today-1]<EXIT)
       {
             close_buy(tradeid, today);
       }



     } 


}//end of for loop 


}


void algotrade::enter_buy(int t)
{
      double value;
       value=GBPUSD[t];
   
       ifopen[tradeid]=1.0;
       entertime[tradeid] = t;

       entervalue[tradeid]=value;
       volume[tradeid]=10000;

       tradeid++;

}

void algotrade::close_buy(int id, int t)
{

       int check=ifopen[id];

       if(check){
            int enter_t;
            double enter_v;
            double close_v;
            double v;

            enter_t=entertime[id];
            enter_v=entervalue[enter_t];
            v=volume[id];
            closetime[id]=t;
            close_v=GBPUSD[t];
            closevalue[id]=close_v;

            double p; 
            p=(close_v-enter_v)*v;
            profit[id]=p; 
       }



}




int main()
{

const int SIZE = 200;

algotrade cable;

for(int i=1;i<=200; i++)
{
     cable.trade(i);
}


return 0;
}
