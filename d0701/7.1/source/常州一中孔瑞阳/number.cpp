#include<cstdio>
using namespace std;
int a[801]={0,1,2,3,4,5,6,7,8,9,12
,13,16,17,20,21,24,25,28,29,32
,33,44,45,48,49,60,61,64,65,80
,81,96,97,112,113,128,129,144,145,192
,193,208,209,256,257,320,321,384,385,448
,449,512,513,704,705,768,769,960,961,1024
,1025,1216,1217,1280,1281,1472,1473,1536,1537,1728
,1729,1792,1793,1984,1985,2048,2049,2304,2305,2752
,2753,3008,3009,3072,3073,3328,3329,3776,3777,4032
,4033,4096,4097,4352,4353,4800,4801,5056,5057,5120
,5121,5376,5377,5824,5825,6080,6081,6144,6145,6400
,6401,6848,6849,7104,7105,7168,7169,7424,7425,7872
,7873,8128,8129,8192,8193,9152,9153,9472,9473,9920
,9921,10496,10497,10944,10945,11264,11265,12224,12225,12288
,12289,13248,13249,13568,13569,14016,14017,14592,14593,15040
,15041,15360,15361,16320,16321,16384,16385,17344,17345,18112
,18113,19136,19137,20480,20481,21440,21441,22208,22209,23232
,23233,24576,24577,25536,25537,26304,26305,27328,27329,28672
,28673,29632,29633,30400,30401,31424,31425,32768,32769,36864
,36865,41920,41921,42688,42689,43712,43713,46016,46017,46784
,46785,47808,47809,49152,49153,53248,53249,58304,58305,59072
,59073,60096,60097,62400,62401,63168,63169,64192,64193,65536
,65537,76480,76481,78784,78785,79552,79553,81920,81921,92864
,92865,95168,95169,95936,95937,98304,98305,109248,109249,111552
,111553,112320,112321,114688,114689,125632,125633,127936,127937,128704
,128705,131072,131073,142016,142017,144320,144321,161472,161473,177856
,177857,180224,180225,191168,191169,193472,193473,196608,196609,207552
,207553,209856,209857,227008,227009,243392,243393,245760,245761,256704
,256705,259008,259009,262144,262145,275392,275393,292544,292545,311296
,311297,324544,324545,327680,327681,340928,340929,358080,358081,376832
,376833,390080,390081,393216,393217,406464,406465,423616,423617,442368
,442369,455616,455617,458752,458753,472000,472001,489152,489153,507904
,507905,521152,521153,524288,524289,537536,537537,554688,554689,573440
,573441,586688,586689,589824,589825,603072,603073,620224,620225,638976
,638977,652224,652225,786432,786433,799680,799681,816832,816833,835584
,835585,848832,848833,851968,851969,865216,865217,882368,882369,901120
,901121,914368,914369,1048576,1048577,1078976,1078977,1097728,1097729,1114112
,1114113,1144512,1144513,1163264,1163265,1310720,1310721,1341120,1341121,1359872
,1359873,1376256,1376257,1406656,1406657,1425408,1425409,1572864,1572865,1603264
,1603265,1622016,1622017,1638400,1638401,1668800,1668801,1687552,1687553,1835008
,1835009,1865408,1865409,1884160,1884161,1900544,1900545,1930944,1930945,1949696
,1949697,2097152,2097153,2146304,2146305,2162688,2162689,2211840,2211841,2389696
,2389697,2455232,2455233,2651840,2651841,2717376,2717377,2883584,2883585,2932736
,2932737,2949120,2949121,2998272,2998273,3145728,3145729,3194880,3194881,3211264
,3211265,3260416,3260417,3438272,3438273,3503808,3503809,3700416,3700417,3765952
,3765953,3932160,3932161,3981312,3981313,3997696,3997697,4046848,4046849,4194304
,4194305,4308992,4308993,4552384,4552385,4814528,4814529,5029888,5029889,5046272
,5046273,5242880,5242881,5357568,5357569,5600960,5600961,5863104,5863105,6078464
,6078465,6094848,6094849,6291456,6291457,6406144,6406145,6649536,6649537,6911680
,6911681,7127040,7127041,7143424,7143425,7340032,7340033,7454720,7454721,7698112
,7698113,7960256,7960257,8175616,8175617,8192000,8192001,8388608,8388609,8503296
,8503297,8746688,8746689,9240576,9240577,9437184,9437185,9551872,9551873,9795264
,9795265,10289152,10289153,11105984,11105985,11321344,11321345,12154560,12154561,12369920
,12369921,12582912,12582913,12697600,12697601,12940992,12940993,13434880,13434881,13631488
,13631489,13746176,13746177,13989568,13989569,14483456,14483457,15300288,15300289,15515648
,15515649,16348864,16348865,16564224,16564225,16777216,16777217,17940480,17940481,18183872
,18183873,18677760,18677761,19494592,19494593,20758528,20758529,20971520,20971521,22134784
,22134785,22378176,22378177,22872064,22872065,23688896,23688897,24952832,24952833,25165824
,25165825,26329088,26329089,26572480,26572481,27066368,27066369,27883200,27883201,29147136
,29147137,29360128,29360129,30523392,30523393,30766784,30766785,31260672,31260673,32077504
,32077505,33341440,33341441,33554432,33554433,34717696,34717697,35454976,35454977,36271808
,36271809,37535744,37535745,39155392,39155393,43349696,43349697,46137344,46137345,47300608
,47300609,48037888,48037889,48854720,48854721,50118656,50118657,50331648,50331649,51494912
,51494913,52232192,52232193,53049024,53049025,54312960,54312961,55932608,55932609,60126912
,60126913,62914560,62914561,64077824,64077825,64815104,64815105,65631936,65631937,66895872
,66895873,67108864,67108865,68272128,68272129,71090176,71090177,72709824,72709825,79691776
,79691777,80855040,80855041,83673088,83673089,83886080,83886081,85049344,85049345,87867392
,87867393,89487040,89487041,96468992,96468993,97632256,97632257,100450304,100450305,100663296
,100663297,101826560,101826561,104644608,104644609,106264256,106264257,113246208,113246209,114409472
,114409473,117227520,117227521,117440512,117440513,118603776,118603777,121421824,121421825,123041472
,123041473,130023424,130023425,131186688,131186689,134004736,134004737,134217728,134217729,139818688
,139818689,147963904,147963905,150781952,150781953,150994944,150994945,156595904,156595905,164741120
,164741121,167559168,167559169,168935424,168935425,171753472,171753473,180355072,180355073,185712640
,185712641,188530688,188530689,197132288,197132289,201326592,201326593,206927552,206927553,215072768
,215072769,217890816,217890817,218103808,218103809,223704768,223704769,231849984,231849985,234668032
,234668033,236044288,236044289,238862336,238862337,247463936,247463937,252821504,252821505,255639552
,255639553,264241152,264241153,268435456,268435457,285212672,285212673,335544320,335544321,352321536
,352321537,402653184,402653185,419430400,419430401,469762048,469762049,486539264,486539265,536870912
,536870913,620756992,620756993,687865856,687865857,738197504,738197505,805306368,805306369,889192448
,889192449,956301312,956301313,1006632960,1006632961,1073741824,1073741825,1157627904,1157627905,1224736768};
int b[40],n,l=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&n); 
	for(n=a[n];n;n>>=1)b[++l]=n&1;
	for(int i=l;i;i--)printf("%d",b[i]);
	printf("\n"); return 0;
}
