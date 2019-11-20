#ifndef _COEFICIENTS_HPP_
#define _COEFICIENTS_HPP_

class coef
{

public:
unsigned int p[10] =
{
2358630,2358630,2358630,3145284,4194304,5593194,7458644,7458644,7458644,7458644};

unsigned int pr[9] =
{
5,10,19,35,70,117,163,232,348};

unsigned int x_re[1024] =
{
15655040,16132415,272948,215466,16436248,16729868,629496,40430,14852364,16613988,
13976601,14817829,996069,538469,14576257,15860539,15812511,2437246,13874372,11684320,
2240721,13231254,757302,88920,402011,114680,16732197,536809,16707743,15715537,
1166387,217518,16665390,561707,73766,16385572,253670,110813,990329,16369806,
340533,78503,848315,16721469,16610365,318130,828697,16724374,16507994,16738427,
91832,16673651,16485001,376352,956700,16437071,113181,16765309,16266113,689607,
842891,200064,16199646,16674952,16635295,691711,26970,16761252,99336,117352,
28334,1000076,16569665,223880,117867,15844136,16483697,16344069,16651568,16460647,
294478,154192,16651920,16610683,206788,9572,35445,59022,725748,578729,
338019,15718312,16506243,380796,16152564,347729,78524,16548974,466274,285803,
16462678,200805,16482654,49631,16730754,16694727,16718792,16715548,16708855,16711228,
16711641,11234,22186,16746108,16754179,16776599,93491,27771,16683589,16732697,
13741,73772,16746280,16679027,51494,62450,5581,16775521,16686175,25623,
34223,6685,31423,432,3277,61077,16776937,16713275,79315,26275,
69101,16754891,16767814,16753197,1254,16767030,15944,16770482,9596,16773620,
16756419,16773293,16777183,16749719,16770710,16772563,19740,16763929,16753615,16769976,
2931,16766647,16750856,16733242,16754776,27193,16772627,16768908,16755679,16753312,
6428,8517,16767271,16757527,16761658,16754267,16772300,2446,16756262,16764384,
16758064,16769447,16772361,16766420,16765451,16776719,16774346,14063,16765956,16746781,
16769869,16772384,21982,16748231,16771177,16755221,16771042,8009,16769665,16769907,
16744490,16773386,16772833,1379,16762510,16770077,16769866,16771985,16753198,16758532,
16774779,10327,14316,16752079,15,16754039,16771904,16761258,16767194,16768285,
16757134,16771027,16762218,6309,16746286,7394,16759836,16771433,16771214,16766636,
16770362,16773768,16769550,16759675,16772408,16762743,16774287,16759864,16771193,16758336,
16757471,16773845,16770159,16766000,16761172,16772205,16754913,2747,16763814,16768216,
16770206,16770312,16775534,16756046,16771838,16755652,16766592,16754929,16768870,16763419,
16766617,16763244,16764069,16774535,16762813,16768794,16766025,16759720,16775944,16760089,
16769352,16768927,16771449,16751798,16771991,16765043,16774187,16760193,16766827,16762443,
16762123,16774463,16769988,16767861,16762963,16772411,16767275,16770772,16764578,16775745,
16760321,16761815,16767709,16766012,16775374,16761126,16767224,16769923,16766889,16758385,
16769315,16772287,16761892,16769495,16755413,16769583,16770548,16772023,16767441,16755991,
16762319,16754388,16776603,16758899,16772592,16755769,16774322,16764177,16775781,16759709,
16771496,16769991,16755051,16773668,16760510,16755938,16763992,16768722,16769797,16762375,
16764867,16765734,16769100,16767749,16768581,16751815,16765607,16769773,16767261,16767330,
16764497,16768108,16747949,16761343,16757927,16767000,16760380,16761569,16770143,16755677,
2028,16749239,2325,16749654,2960,16763693,16760733,16758285,16760057,16764935,
16766827,16776023,16761473,16763887,16748898,16770727,16743125,16763387,196,16772024,
16765297,16754649,16763799,16751304,11155,16761602,16765098,16761309,16772752,16766571,
16764317,16757041,16764292,16754020,16758945,16770101,2477,3673,16758341,16762580,
16769293,16745903,920,16755594,16754095,8758,16753712,16751433,16775150,16764570,
16763508,16770330,11791,16775637,16767241,16752161,16767358,16764895,16769764,624,
57,16762253,16771087,16768414,16748104,16748327,758,4019,16771158,16773193,
16761018,16770419,16761518,16768016,16741114,16762479,16756615,16771188,16762239,16763014,
16762572,16747499,2350,16768379,16771080,16744213,16772017,16762511,16756829,16766398,
16733723,32323,16775668,16763365,13883,16774132,20886,16769931,16745691,16740378,
16774760,16763978,16772024,4071,16760897,16756478,38160,16765519,18504,16741665,
16726488,26110,16746963,16736019,20262,16747447,16740407,16757094,8365,5103,
16753888,16748681,16771642,16745335,3052,16765006,16774392,50651,14024,16761738,
16740551,16766717,16768838,16766242,16758398,10329,4689,2500,16764127,16751234,
16767602,9291,16752257,32391,16774486,20516,15823,1164,16765612,17414,
16776833,16768003,38813,16770077,16741180,16759027,16754562,16771595,16759617,16757411,
16762045,16737104,31872,16737104,16762045,16757411,16759617,16771595,16754562,16759027,
16741180,16770077,38813,16768003,16776833,17414,16765612,1164,15823,20516,
16774486,32391,16752257,9291,16767602,16751234,16764127,2500,4689,10329,
16758398,16766242,16768838,16766717,16740551,16761738,14024,50651,16774392,16765006,
3052,16745335,16771642,16748681,16753888,5103,8365,16757094,16740407,16747447,
20262,16736019,16746963,26110,16726488,16741665,18504,16765519,38160,16756478,
16760897,4071,16772024,16763978,16774760,16740378,16745691,16769931,20886,16774132,
13883,16763365,16775668,32323,16733723,16766398,16756829,16762511,16772017,16744213,
16771080,16768379,2350,16747499,16762572,16763014,16762239,16771188,16756615,16762479,
16741114,16768016,16761518,16770419,16761018,16773193,16771158,4019,758,16748327,
16748104,16768414,16771087,16762253,57,624,16769764,16764895,16767358,16752161,
16767241,16775637,11791,16770330,16763508,16764570,16775150,16751433,16753712,8758,
16754095,16755594,920,16745903,16769293,16762580,16758341,3673,2477,16770101,
16758945,16754020,16764292,16757041,16764317,16766571,16772752,16761309,16765098,16761602,
11155,16751304,16763799,16754649,16765297,16772024,196,16763387,16743125,16770727,
16748898,16763887,16761473,16776023,16766827,16764935,16760057,16758285,16760733,16763693,
2960,16749654,2325,16749239,2028,16755677,16770143,16761569,16760380,16767000,
16757927,16761343,16747949,16768108,16764497,16767330,16767261,16769773,16765607,16751815,
16768581,16767749,16769100,16765734,16764867,16762375,16769797,16768722,16763992,16755938,
16760510,16773668,16755051,16769991,16771496,16759709,16775781,16764177,16774322,16755769,
16772592,16758899,16776603,16754388,16762319,16755991,16767441,16772023,16770548,16769583,
16755413,16769495,16761892,16772287,16769315,16758385,16766889,16769923,16767224,16761126,
16775374,16766012,16767709,16761815,16760321,16775745,16764578,16770772,16767275,16772411,
16762963,16767861,16769988,16774463,16762123,16762443,16766827,16760193,16774187,16765043,
16771991,16751798,16771449,16768927,16769352,16760089,16775944,16759720,16766025,16768794,
16762813,16774535,16764069,16763244,16766617,16763419,16768870,16754929,16766592,16755652,
16771838,16756046,16775534,16770312,16770206,16768216,16763814,2747,16754913,16772205,
16761172,16766000,16770159,16773845,16757471,16758336,16771193,16759864,16774287,16762743,
16772408,16759675,16769550,16773768,16770362,16766636,16771214,16771433,16759836,7394,
16746286,6309,16762218,16771027,16757134,16768285,16767194,16761258,16771904,16754039,
15,16752079,14316,10327,16774779,16758532,16753198,16771985,16769866,16770077,
16762510,1379,16772833,16773386,16744490,16769907,16769665,8009,16771042,16755221,
16771177,16748231,21982,16772384,16769869,16746781,16765956,14063,16774346,16776719,
16765451,16766420,16772361,16769447,16758064,16764384,16756262,2446,16772300,16754267,
16761658,16757527,16767271,8517,6428,16753312,16755679,16768908,16772627,27193,
16754776,16733242,16750856,16766647,2931,16769976,16753615,16763929,19740,16772563,
16770710,16749719,16777183,16773293,16756419,16773620,9596,16770482,15944,16767030,
1254,16753197,16767814,16754891,69101,26275,79315,16713275,16776937,61077,
3277,432,31423,6685,34223,25623,16686175,16775521,5581,62450,
51494,16679027,16746280,73772,13741,16732697,16683589,27771,93491,16776599,
16754179,16746108,22186,11234,16711641,16711228,16708855,16715548,16718792,16694727,
16730754,49631,16482654,200805,16462678,285803,466274,16548974,78524,347729,
16152564,380796,16506243,15718312,338019,578729,725748,59022,35445,9572,
206788,16610683,16651920,154192,294478,16460647,16651568,16344069,16483697,15844136,
117867,223880,16569665,1000076,28334,117352,99336,16761252,26970,691711,
16635295,16674952,16199646,200064,842891,689607,16266113,16765309,113181,16437071,
956700,376352,16485001,16673651,91832,16738427,16507994,16724374,828697,318130,
16610365,16721469,848315,78503,340533,16369806,990329,110813,253670,16385572,
73766,561707,16665390,217518,1166387,15715537,16707743,536809,16732197,114680,
402011,88920,757302,13231254,2240721,11684320,13874372,2437246,15812511,15860539,
14576257,538469,996069,14817829,13976601,16613988,14852364,40430,629496,16729868,
16436248,215466,272948,16132415};

unsigned int x_im[1024] =
{
0,55263,79494,66516,16421400,115388,16367013,16464055,15522321,65256,
2293061,81287,266564,14550536,6397909,9686352,7051214,1808899,1196761,355531,
510823,14278763,15855652,16624130,132782,386243,16637421,16724440,16413380,146698,
2322551,15921960,15932540,209791,228147,16456542,10337,41945,16205557,295716,
16754505,16078970,84785,16485131,16532396,16364802,15454044,1702079,244718,261883,
479828,16689566,487198,257272,422952,16735146,16740192,16373293,616444,16094660,
16215114,16409570,16717867,256956,7226,273424,351690,163850,5600,356707,
16588668,16294994,16207775,434217,815249,16262248,16340990,16516518,92582,15158842,
16585164,67890,154621,155106,69459,16296890,16664097,16595945,389974,572431,
302694,210557,885,83171,16469979,43478,171679,8098,16548029,289672,
162946,357372,27980,16619081,165166,122443,142102,73372,81895,153399,
199531,196852,16488357,10026,5808,16774157,272455,16772605,16776450,47066,
103027,16734575,16711224,40208,98709,44319,56665,16776118,85482,16671581,
66288,16775494,67624,86742,80405,49219,24914,16760113,87399,66801,
56083,41168,49629,45202,69445,61246,33510,63306,53638,57793,
58506,62858,3776,18394,34503,19905,54369,29334,14727,48993,
38370,47985,8348,46736,65483,56716,13592,20441,32503,33864,
38872,36380,31069,41278,37197,29238,31712,16041,37723,27492,
37360,12661,35264,6436,17373,25271,26022,39046,50905,16772930,
37914,40252,20599,26966,25796,31604,38200,18149,27528,21510,
40350,12893,30566,14217,24054,32938,26722,33058,21212,27476,
20849,37271,9885,22440,25722,16055,31916,18017,28115,12855,
30462,17501,38655,11556,35476,24743,21314,31673,26096,22576,
22464,25564,11036,20057,14797,28083,30203,7827,27590,12518,
29641,23497,24487,21675,22231,25862,22468,15818,7658,33736,
5942,21126,17522,25645,30677,8700,19456,21285,26742,14222,
24045,9556,20848,11244,18605,31260,6884,27854,13884,23928,
11880,29592,2410,24227,30691,20225,10881,15158,27987,26821,
20591,28799,18765,22914,11999,15273,8914,19163,16943,22037,
18340,20682,10869,10976,8186,11990,27292,6118,29614,14517,
21248,10618,7973,16421,7700,20546,21649,11052,8948,24790,
8126,17067,10142,13542,8562,17817,24617,9788,12708,12181,
16565,4360,19733,18629,4521,10301,13605,10653,20956,13785,
9367,15437,15419,2501,19088,2528,25068,7999,12721,16939,
5543,16774037,12322,18155,11552,21455,11277,14430,3453,15908,
10995,9057,16326,5807,21167,15774,7103,3864,8482,10530,
17859,4773,12681,4879,13987,10321,810,13123,16849,18643,
12320,15433,16776687,9387,15623,7083,7933,24269,20930,10646,
17271,17389,15917,16773303,16753642,2468,26333,2020,16774448,5174,
12753,17017,15725,18784,2073,16766145,5342,2988,29978,13815,
13045,19262,18858,29534,4638,5885,4026,10977,16767551,3655,
16777124,31920,13587,11335,37778,9267,18582,2693,1710,22814,
16757609,1961,16756869,16771710,16757792,14966,24601,9761,5647,15239,
16838,26842,16760577,15599,28954,1146,23124,19890,16775104,16760061,
24095,15987,16771078,20982,5366,4886,16769476,16759551,13432,16761361,
6707,26651,16772388,16761128,12039,16757023,25542,16748506,9850,16772201,
4859,16769536,23427,10478,16776719,16766759,18736,16764425,8593,13568,
23512,15590,6038,24823,23085,39193,16773,16776961,10877,3570,
16761898,16774721,28781,29874,16768992,777,2950,2606,16760478,22230,
16752526,6635,12367,16771005,16762177,32949,16772593,4399,6638,16771178,
7689,16756716,16744661,23360,8412,9367,25614,16187,16766376,15341,
16421,29055,0,16748161,16760795,16761875,10840,16761029,16751602,16767849,
16768804,16753856,32555,20500,16769527,6038,16770578,16772817,4623,16744267,
15039,6211,16764849,16770581,24690,16754986,16738,16774610,16774266,16776439,
8224,16747342,16748435,2495,15318,16773646,16766339,255,16760443,16738023,
16754131,16752393,16771178,16761626,16753704,16763648,16768623,12791,16758480,10457,
497,16766738,16753789,7680,16772357,5015,16767366,28710,16751674,20193,
16765177,16088,4828,16750565,16770509,15855,16763784,17665,7740,16772330,
16771850,16756234,6138,16761229,16753121,17155,2112,16757326,16754092,16776070,
16748262,16761617,16639,16750374,16760378,16761977,16771569,16767455,16752615,16762250,
19424,5506,20347,16775255,19607,16754402,16775506,16774523,16758634,16767949,
16739438,16765881,16763629,16745296,92,16773561,9665,16766239,16773190,16771331,
16772578,16747682,16758358,16757954,16764171,16763401,16747238,16774228,16771874,11071,
16775143,16758432,16761491,16760199,16764463,16772042,2768,16775196,16750883,16774748,
23574,3913,16761299,16759827,16759945,16766570,16756286,16752947,16769283,16770133,
16761593,16767829,529,16761783,16764896,16758573,16760367,16764093,16776406,16766895,
16763229,16772337,16764535,16772443,16759357,16766686,16768734,16773352,16770113,16761442,
16756049,16771409,16760890,16768159,16766221,16761308,16773763,16762786,16765939,16755761,
16765664,16759061,16764894,3179,16771673,16760277,16764495,16769217,16752148,16774688,
16758128,16774715,16761797,16761779,16767849,16763431,16756260,16766563,16763611,16766915,
16772695,16758587,16757483,16772856,16760651,16765035,16764508,16767428,16752599,16759399,
16768654,16763674,16767074,16760149,16769090,16752426,16768268,16766164,16755567,16756670,
16769516,16760795,16769243,16766598,16755968,16762699,16747602,16771098,16749924,16765226,
16769030,16766240,16766347,16756534,16758876,16755179,16760273,16758053,16768302,16761943,
16765217,16754302,16758451,16748417,16756625,16750395,16749229,16762058,16766335,16756991,
16746525,16752989,16774806,16747624,16765336,16753288,16763332,16749362,16770332,16745956,
16758611,16765972,16756368,16767660,16753171,16762994,16750474,16755931,16757760,16768516,
16746539,16751571,16759694,16756090,16771274,16743480,16769558,16761398,16754748,16751354,
16754985,16755541,16752729,16753719,16747575,16764698,16749626,16769389,16747013,16749133,
16762419,16757159,16766180,16751652,16754752,16754640,16751120,16745543,16755902,16752473,
16741740,16765660,16738561,16759715,16746754,16764361,16749101,16759199,16745300,16761161,
16751494,16754776,16767331,16739945,16756367,16749740,16756004,16744158,16750494,16744278,
16753162,16762999,16746650,16764323,16736866,16755706,16749688,16759067,16739016,16745612,
16751420,16750250,16756617,16736964,16739302,4286,16726311,16738170,16751194,16751945,
16759843,16770780,16741952,16764555,16739856,16749724,16739493,16761175,16745504,16747978,
16740019,16735938,16746147,16740836,16738344,16743352,16744713,16756775,16763624,16720500,
16711733,16730480,16768868,16729231,16738846,16728223,16762489,16747882,16722847,16757311,
16742713,16758822,16773440,16714358,16718710,16719423,16723578,16713910,16743706,16715970,
16707771,16732014,16727587,16736048,16721133,16710415,16689817,17103,16752302,16727997,
16696811,16690474,16709592,1722,16710928,105635,16691734,1098,16720551,16732897,
16678507,16737008,65992,42641,16674189,16730150,766,4611,16504761,3059,
16771408,16767190,288859,16580364,16577685,16623817,16695321,16703844,16635114,16654773,
16612050,158135,16749236,16419844,16614270,16487544,229187,16769118,16605537,16733738,
307237,16694045,16776331,16566659,16474522,16204785,16387242,181271,113119,480326,
16707757,16622110,16622595,16709326,192052,1618374,16684634,260698,436226,514968,
15961967,16342999,569441,482222,188548,16420509,16771616,16613366,16425526,16503792,
16769990,16520260,59349,367646,562102,682556,16160772,403923,37024,42070,
16354264,16519944,16290018,87650,16297388,16515333,16532498,15075137,1323172,412414,
244820,292085,16692431,698246,22711,16481500,571659,16735271,16766879,320674,
16549069,16567425,844676,855256,14454665,16630518,363836,52776,139795,16390973,
16644434,153086,921564,2498453,16266393,16421685,15580455,14968317,9726002,7090864,
10379307,2226680,16510652,16695929,14484155,16711960,1254895,313161,410203,16661828,
355816,16710700,16697722,16721953};

unsigned int y_re[1024] =
{
16146170,16414618,153490,121166,16585476,16750590,353992,22735,15694792,16685426,
15202315,15675372,560131,302804,15539526,16261731,16234722,1370564,15144827,12958083,
1680304,14118119,567896,66681,301465,85998,16743456,402550,16725118,15981069,
874667,163116,16693359,421221,55316,16385572,253670,110813,990329,16369806,
340533,78503,848315,16721469,16610365,318130,828697,16724374,16507994,16738427,
91832,16673651,16485001,376352,956700,16437071,113181,16765309,16266113,689607,
842891,200064,16199646,16674952,16635295,691711,26970,16761252,99336,117352,
37784,1333623,16500442,298549,157178,15532934,16385802,16199605,16609662,16355064,
392693,205619,16610131,16555140,275756,12765,47267,78707,967801,771747,
450755,15365145,16415868,507800,15944230,463704,104714,16472851,621786,381125,
16357773,267778,16384411,66184,16715258,16667215,16699306,16694981,16686055,16689219,
16689770,14981,29586,16735733,16746495,16776393,124672,49385,16610721,16698049,
24436,131186,16722204,16602609,91571,111054,9924,16774202,16615320,45565,
60859,11887,55879,769,5828,108611,16776719,16663512,141043,46724,
122881,16737515,16760496,16734503,2230,16759102,28352,16765242,17065,16770822,
16740233,16770240,16777157,16728319,16765647,16768941,35103,16753588,16735247,16764341,
5212,16758421,16730341,16699019,16737312,48357,16769056,16762442,16738917,16734707,
11431,15146,16759532,16742204,16749549,16736405,16768474,4350,16739953,16754397,
16743159,16763401,16768582,16758017,16756294,16776332,16772113,25007,16757193,16723094,
16764151,16768623,39090,16725672,16766477,16738103,16766237,14242,16763788,16764219,
16719020,16770405,16769422,2452,16751064,16764520,16764146,16767914,16734506,16743991,
16772882,18364,25457,16732516,27,16736001,16767771,16748838,16759394,16761334,
16741505,16766211,16750545,11218,16722214,13148,16746309,16766932,16766543,16758402,
16765028,16771084,16763584,16746023,16768666,16751479,16772007,16746360,16766506,16743643,
16742103,16771221,16764667,16757270,16748685,16768306,16737556,4885,16753384,16761212,
16764749,16764938,16774224,16739570,16767652,16738870,16758324,16737584,16762375,16752682,
16758368,16752370,16753837,16772449,16751604,16762240,16757315,16746103,16774954,16746759,
16763231,16762476,16766960,16732017,16767924,16755568,16771829,16746944,16758741,16750946,
16750377,16772320,16764362,16760580,16751870,16768672,16759538,16765757,16754742,16774601,
16747172,16749828,16760310,16757292,16773940,16748603,16759447,16764246,16758853,16743729,
16763165,16768451,16749966,16763485,16738445,16763643,16765358,16767981,16759832,16739473,
16750725,16736622,16776126,16744644,16768993,16739077,16772069,16754030,16774664,16746083,
16767045,16764369,16737800,16770906,16747509,16739378,16753700,16762111,16764024,16750825,
16755256,16756798,16762784,16760382,16761860,16732046,16756572,16763980,16759513,16759635,
16754599,16761019,16725171,16748989,16742914,16759049,16747276,16749392,16764638,16738913,
3606,16727465,4135,16728203,5264,16753168,16747905,16743552,16746702,16755378,
16758742,16775095,16749221,16753514,16726858,16765676,16716592,16752624,349,16767984,
16756020,16737086,16753357,16731138,19836,16749450,16755667,16748929,16769277,16758286,
16754278,16741339,16754233,16735968,16744725,16764563,4405,6532,16743650,16751188,
16763127,16721533,1637,16738766,16736100,15574,16735420,16731367,16773542,16754728,
16752840,16764970,20968,16774408,16759478,16732661,16759686,16755306,16763964,1109,
101,16750607,16766317,16761564,16725448,16725843,1348,7147,16766444,16770061,
16748412,16765128,16749301,16760856,16713016,16751010,16740582,16766497,16750582,16751961,
16751175,16724371,4178,16761502,16766305,16718528,16767971,16751066,16740962,16757979,
16699874,57479,16774463,16752585,24688,16771731,37140,16764261,16721156,16711708,
16772849,16753676,16767983,7239,16748197,16740338,67859,16756415,32904,16713997,
16687007,46432,16723417,16703956,36031,16724278,16711759,16741433,14875,9075,
16735731,16726473,16767304,16720523,5428,16755503,16772195,90072,24938,16749691,
16712015,16758546,16762317,16757701,16743753,18368,8339,4445,16753940,16731012,
16760120,16522,16732831,57601,16772362,36483,28137,2070,16756582,30967,
16776534,16760832,69021,16764521,16713133,16744871,16736931,16767220,16745919,16741997,
16750238,16705885,56677,16705885,16750238,16741997,16745919,16767220,16736931,16744871,
16713133,16764521,69021,16760832,16776534,30967,16756582,2070,28137,36483,
16772362,57601,16732831,16522,16760120,16731012,16753940,4445,8339,18368,
16743753,16757701,16762317,16758546,16712015,16749691,24938,90072,16772195,16755503,
5428,16720523,16767304,16726473,16735731,9075,14875,16741433,16711759,16724278,
36031,16703956,16723417,46432,16687007,16713997,32904,16756415,67859,16740338,
16748197,7239,16767983,16753676,16772849,16711708,16721156,16764261,37140,16771731,
24688,16752585,16774463,57479,16699874,16757979,16740962,16751066,16767971,16718528,
16766305,16761502,4178,16724371,16751175,16751961,16750582,16766497,16740582,16751010,
16713016,16760856,16749301,16765128,16748412,16770061,16766444,7147,1348,16725843,
16725448,16761564,16766317,16750607,101,1109,16763964,16755306,16759686,16732661,
16759478,16774408,20968,16764970,16752840,16754728,16773542,16731367,16735420,15574,
16736100,16738766,1637,16721533,16763127,16751188,16743650,6532,4405,16764563,
16744725,16735968,16754233,16741339,16754278,16758286,16769277,16748929,16755667,16749450,
19836,16731138,16753357,16737086,16756020,16767984,349,16752624,16716592,16765676,
16726858,16753514,16749221,16775095,16758742,16755378,16746702,16743552,16747905,16753168,
5264,16728203,4135,16727465,3606,16738913,16764638,16749392,16747276,16759049,
16742914,16748989,16725171,16761019,16754599,16759635,16759513,16763980,16756572,16732046,
16761860,16760382,16762784,16756798,16755256,16750825,16764024,16762111,16753700,16739378,
16747509,16770906,16737800,16764369,16767045,16746083,16774664,16754030,16772069,16739077,
16768993,16744644,16776126,16736622,16750725,16739473,16759832,16767981,16765358,16763643,
16738445,16763485,16749966,16768451,16763165,16743729,16758853,16764246,16759447,16748603,
16773940,16757292,16760310,16749828,16747172,16774601,16754742,16765757,16759538,16768672,
16751870,16760580,16764362,16772320,16750377,16750946,16758741,16746944,16771829,16755568,
16767924,16732017,16766960,16762476,16763231,16746759,16774954,16746103,16757315,16762240,
16751604,16772449,16753837,16752370,16758368,16752682,16762375,16737584,16758324,16738870,
16767652,16739570,16774224,16764938,16764749,16761212,16753384,4885,16737556,16768306,
16748685,16757270,16764667,16771221,16742103,16743643,16766506,16746360,16772007,16751479,
16768666,16746023,16763584,16771084,16765028,16758402,16766543,16766932,16746309,13148,
16722214,11218,16750545,16766211,16741505,16761334,16759394,16748838,16767771,16736001,
27,16732516,25457,18364,16772882,16743991,16734506,16767914,16764146,16764520,
16751064,2452,16769422,16770405,16719020,16764219,16763788,14242,16766237,16738103,
16766477,16725672,39090,16768623,16764151,16723094,16757193,25007,16772113,16776332,
16756294,16758017,16768582,16763401,16743159,16754397,16739953,4350,16768474,16736405,
16749549,16742204,16759532,15146,11431,16734707,16738917,16762442,16769056,48357,
16737312,16699019,16730341,16758421,5212,16764341,16735247,16753588,35103,16768941,
16765647,16728319,16777157,16770240,16740233,16770822,17065,16765242,28352,16759102,
2230,16734503,16760496,16737515,122881,46724,141043,16663512,16776719,108611,
5828,769,55879,11887,60859,45565,16615320,16774202,9924,111054,
91571,16602609,16722204,131186,24436,16698049,16610721,49385,124672,16776393,
16746495,16735733,29586,14981,16689770,16689219,16686055,16694981,16699306,16667215,
16715258,66184,16384411,267778,16357773,381125,621786,16472851,104714,463704,
15944230,507800,16415868,15365145,450755,771747,967801,78707,47267,12765,
275756,16555140,16610131,205619,392693,16355064,16609662,16199605,16385802,15532934,
157178,298549,16500442,1333623,37784,117352,99336,16761252,26970,691711,
16635295,16674952,16199646,200064,842891,689607,16266113,16765309,113181,16437071,
956700,376352,16485001,16673651,91832,16738427,16507994,16724374,828697,318130,
16610365,16721469,848315,78503,340533,16369806,990329,110813,253670,16385572,
55316,421221,16693359,163116,874667,15981069,16725118,402550,16743456,85998,
301465,66681,567896,14118119,1680304,12958083,15144827,1370564,16234722,16261731,
15539526,302804,560131,15675372,15202315,16685426,15694792,22735,353992,16750590,
16585476,121166,153490,16414618};

unsigned int y_im[1024] =
{
0,31077,44703,37405,16577126,64888,16546542,16601112,16071536,36696,
1289483,45711,149900,15525062,3597808,12789730,3965189,1017219,672988,266611,
383063,14903641,16086140,16662418,99572,289642,16672384,16737640,16504378,110008,
1741668,16135865,16143799,157321,171086,16456542,10337,41945,16205557,295716,
16754505,16078970,84785,16485131,16532396,16364802,15454044,1702079,244718,261883,
479828,16689566,487198,257272,422952,16735146,16740192,16373293,616444,16094660,
16215114,16409570,16717867,256956,7226,273424,351690,163850,5600,356707,
16525783,16134162,16017854,579037,1087152,16090496,16195499,16429569,123461,14619079,
16521111,90533,206190,206838,92625,16136692,16626370,16535488,520039,763349,
403648,280782,1181,110910,16367509,57979,228938,10798,16471590,386284,
217292,476563,37312,16566339,220252,163281,189497,97843,109209,204561,
266079,262506,16392017,13370,7745,16773137,363324,16769016,16775854,83696,
183210,16701389,16659864,71500,175532,78812,100767,16775264,152011,16589368,
117878,16774154,120255,154252,142983,87524,44304,16746802,155420,118790,
99732,73208,88254,80382,123493,108913,59590,112576,95383,102773,
104040,111779,6714,32709,61357,35396,96682,52164,26189,87122,
68232,85331,14845,83110,116448,100856,24170,36349,57800,60219,
69124,64694,55250,73404,66146,51992,56394,28525,67083,48889,
66436,22515,62709,11444,30895,44939,46274,69434,90523,16769594,
67422,71579,36630,47954,45873,56202,67930,32275,48952,38251,
71754,22928,54355,25281,42776,58572,47519,58786,37721,48860,
37076,66278,17578,39905,45741,28551,56755,32039,49996,22859,
54169,31121,68740,20550,63085,43999,37902,56323,46406,40147,
39947,45460,19626,35668,26312,49939,53710,13918,49062,22260,
52711,41784,43545,38545,39533,45990,39954,28128,13618,59992,
10567,37568,31159,45604,54553,15472,34598,37851,47554,25291,
42758,16993,37074,19994,33084,55590,12242,49533,24690,42550,
21126,52623,4286,43083,54577,35966,19350,26956,49769,47695,
36617,51212,33369,40748,21338,27161,15851,34077,30129,39187,
32614,36778,19328,19518,14557,21322,48533,10880,52662,25815,
37786,18882,14178,29202,13692,36536,38498,19653,15913,44083,
14451,30350,18036,24082,15226,31683,43776,17406,22598,21661,
29457,7753,35091,33127,8040,18317,24193,18944,37266,24513,
16656,27451,27420,4447,33943,4495,44577,14225,22621,30121,
9857,16771562,21912,32284,20542,38153,20054,25660,6141,28288,
19553,16106,29033,10326,37641,28051,12631,6872,15083,18725,
31758,8488,22550,8676,24872,18354,1440,23336,29963,33152,
21909,27445,16776274,16693,27783,12596,14107,43158,37220,18931,
30713,30923,28304,16770257,16735295,4388,46827,3592,16772293,9201,
22679,30261,27963,33403,3686,16757528,9499,5314,53310,24568,
23197,34253,33535,52519,8248,10466,7159,19521,16760029,6499,
16777052,56762,24161,20157,67179,16479,33043,4788,3040,40569,
16742350,3487,16741033,16767424,16742675,26614,43748,17357,10042,27100,
29943,47733,16747628,27740,51489,2039,41121,35371,16773461,16746709,
42848,28430,16766302,37312,9542,8688,16763452,16745802,23886,16749021,
11926,47394,16768631,16748608,21408,16741307,45422,16726162,17516,16768297,
8640,16763559,41659,18634,16776332,16758621,33317,16754470,15280,24127,
41811,27724,10737,44143,41051,69696,29827,16776762,19343,6348,
16749976,16772779,51181,53124,16762591,1381,5246,4634,16747451,39531,
16733310,11799,21991,16766171,16750473,58593,16768996,7822,11804,16766479,
13673,16740761,16719324,41541,14959,16657,45549,28784,16757940,27281,
29201,51668,0,16725548,16748015,16749935,19276,16748432,16731667,16760559,
16762257,16735675,57892,36455,16763543,10737,16765412,16769394,8220,16718623,
26743,11045,16755225,16765417,43906,16737685,29765,16772582,16771970,16775835,
14625,16724092,16726035,4437,27240,16770868,16757873,454,16747389,16707520,
16736165,16733073,16766479,16749492,16735405,16753089,16761936,22746,16743899,18595,
884,16758582,16735557,13657,16768576,8919,16759700,51054,16731794,35909,
16755808,28608,8585,16729822,16765290,28195,16753330,31414,13764,16768528,
16767674,16739904,10914,16748786,16734368,30507,3755,16741845,16736095,16775177,
16725727,16749476,29588,16729483,16747273,16750116,16767174,16759859,16733468,16750602,
34541,9792,36183,16773729,34866,16736647,16774176,16772428,16744173,16760737,
16710037,16757059,16753055,16720454,164,16770717,17187,16757695,16770057,16766750,
16768968,16724697,16743681,16742963,16754019,16752648,16723906,16771902,16767717,19688,
16773530,16743813,16749253,16746955,16754537,16768015,4923,16773624,16730389,16772828,
41921,6959,16748912,16746293,16746503,16758285,16739996,16734058,16763109,16764620,
16749433,16760523,942,16749771,16755307,16744064,16747253,16753880,16775776,16758862,
16752344,16768540,16754666,16768728,16745458,16758491,16762133,16770344,16764585,16749165,
16739575,16766890,16748183,16761110,16757663,16748928,16771075,16751556,16757162,16739063,
16756674,16744932,16755304,5654,16767359,16747095,16754595,16762991,16732639,16772721,
16743273,16772769,16749796,16749765,16760560,16752703,16739950,16758272,16753023,16758899,
16769176,16744089,16742125,16769463,16747759,16755555,16754618,16759810,16733440,16745533,
16761990,16753134,16759180,16746866,16762765,16733133,16761303,16757563,16738718,16740680,
16763524,16748014,16763038,16758334,16739430,16751401,16724554,16766336,16728683,16755894,
16762659,16757698,16757888,16740438,16744602,16738029,16747087,16743139,16761365,16750055,
16755878,16736468,16743847,16726004,16740599,16729521,16727447,16750260,16757866,16741250,
16722639,16734133,16772930,16724593,16756090,16734666,16752526,16727683,16764974,16721626,
16744132,16757222,16740142,16760223,16734458,16751925,16729662,16739365,16742618,16761744,
16722663,16731612,16746057,16739648,16766649,16717224,16763598,16749088,16737262,16731226,
16737683,16738671,16733671,16735432,16724505,16754956,16728154,16763298,16723506,16727277,
16750904,16741548,16757590,16731756,16737269,16737069,16730810,16720893,16739314,16733217,
16714131,16756666,16708476,16746095,16723047,16754357,16727220,16745177,16720461,16748665,
16731475,16737311,16759638,16710938,16740140,16728356,16739495,16718430,16729697,16718644,
16734440,16751935,16722861,16754288,16705462,16738965,16728264,16744941,16709286,16721014,
16731343,16729262,16740586,16705637,16709794,7622,16686693,16707782,16730942,16732277,
16746321,16765772,16714507,16754701,16710780,16728327,16710133,16748691,16720822,16725224,
16711070,16703812,16721966,16712522,16708092,16716997,16719416,16740867,16753046,16676360,
16660768,16694106,16762371,16691885,16708984,16690094,16751027,16725052,16680534,16741820,
16715859,16744507,16770502,16665437,16673176,16674443,16681833,16664640,16717626,16668303,
16653723,16696834,16688962,16704008,16677484,16658426,16621796,30414,16732912,16689692,
16634233,16622964,16656961,3062,16659338,187848,16625205,1952,16676449,16698404,
16601684,16705716,117352,75827,16594006,16693520,1362,8200,16413892,4079,
16769471,16763846,385199,16514710,16511137,16572655,16668007,16679373,16587719,16613935,
16556964,210877,16739904,16300653,16559924,16390932,305626,16766418,16548278,16719237,
409707,16666306,16776035,16496434,16373568,16013867,16257177,241728,150846,640524,
16684591,16570378,16571026,16686683,256105,2158137,16653755,347647,581717,686720,
15690064,16198179,759362,643054,251433,16420509,16771616,16613366,16425526,16503792,
16769990,16520260,59349,367646,562102,682556,16160772,403923,37024,42070,
16354264,16519944,16290018,87650,16297388,16515333,16532498,15075137,1323172,412414,
244820,292085,16692431,698246,22711,16481500,571659,16735271,16766879,320674,
16606130,16619895,633417,641351,15035548,16667208,272838,39576,104832,16487574,
16677644,114798,691076,1873575,16394153,16510605,16104228,15759997,12812027,3987486,
13179408,1252154,16627316,16731505,15487733,16740520,705680,176104,230674,16712328,
200090,16739811,16732513,16746139};
};
#endif