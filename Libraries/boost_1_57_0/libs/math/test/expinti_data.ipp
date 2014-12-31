//  Copyright John Maddock 2008.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

   static const boost::array<boost::array<typename table_type<T>::type, 2>, 336> expinti_data = {{
      {{ SC_(-49.689971923828125), SC_(-0.5189914452467706181911213069148082266893e-23) }}, 
      {{ SC_(-49.490234375), SC_(-0.6362401135264284153452455085506782750647e-23) }}, 
      {{ SC_(-49.47381591796875), SC_(-0.6469829627301154800340680350229540167762e-23) }}, 
      {{ SC_(-49.109668731689453125), SC_(-0.937965617499186961883342318134168114907e-23) }}, 
      {{ SC_(-48.69077301025390625), SC_(-0.1438002258908106326351299430868912629378e-22) }}, 
      {{ SC_(-48.5106964111328125), SC_(-0.1728000132640339028589502655738823027867e-22) }}, 
      {{ SC_(-48.044872283935546875), SC_(-0.2779439615740334951105570945539716295032e-22) }}, 
      {{ SC_(-46.498386383056640625), SC_(-0.1347452831431197364179115494975704338441e-21) }}, 
      {{ SC_(-46.225093841552734375), SC_(-0.1781193691784135039948913637371768811083e-21) }}, 
      {{ SC_(-46.21092987060546875), SC_(-0.1807144449606719884758204680891841205212e-21) }}, 
      {{ SC_(-46.07171630859375), SC_(-0.2083224907084183832424058026703771220474e-21) }}, 
      {{ SC_(-45.99146270751953125), SC_(-0.2261161370639941533874318532661368660359e-21) }}, 
      {{ SC_(-45.54817962646484375), SC_(-0.3556041033058530933762241390777221084271e-21) }}, 
      {{ SC_(-45.04344940185546875), SC_(-0.5955350514558786142053309726857087311429e-21) }}, 
      {{ SC_(-44.921146392822265625), SC_(-0.6748061149415831787816898069300771337011e-21) }}, 
      {{ SC_(-44.366191864013671875), SC_(-0.1189810693892140146725035626514689534384e-20) }}, 
      {{ SC_(-44.065486907958984375), SC_(-0.1617943260346693355541238773884456402131e-20) }}, 
      {{ SC_(-42.564510345458984375), SC_(-0.7508521784292956555049663090063210339236e-20) }}, 
      {{ SC_(-41.65602874755859375), SC_(-0.1902237115363634179207156972256911270036e-19) }}, 
      {{ SC_(-41.643665313720703125), SC_(-0.1926460223216498626564145997341831122167e-19) }}, 
      {{ SC_(-41.46872711181640625), SC_(-0.2304209021566303248261300380232548536606e-19) }}, 
      {{ SC_(-41.400691986083984375), SC_(-0.2470393735589908561748312777657558449938e-19) }}, 
      {{ SC_(-40.7796478271484375), SC_(-0.4665489090348590088892832574733877627252e-19) }}, 
      {{ SC_(-40.712055206298828125), SC_(-0.4999841334502210157248794528480866083337e-19) }}, 
      {{ SC_(-39.510929107666015625), SC_(-0.1711205236582734104034468188313993053133e-18) }}, 
      {{ SC_(-39.3155059814453125), SC_(-0.2090623264737543134488804288570287187466e-18) }}, 
      {{ SC_(-39.270557403564453125), SC_(-0.2189181301371969956898734656820283591514e-18) }}, 
      {{ SC_(-38.26819610595703125), SC_(-0.6117321854640996737992349893398315143733e-18) }}, 
      {{ SC_(-37.9152069091796875), SC_(-0.8785955246457078845733834215638759432102e-18) }}, 
      {{ SC_(-37.628902435302734375), SC_(-0.1178529325141498446240403317681089430123e-17) }}, 
      {{ SC_(-36.91025543212890625), SC_(-0.2463830668835851637664366500894910731401e-17) }}, 
      {{ SC_(-36.849811553955078125), SC_(-0.26215321484857982843437445475200392826e-17) }}, 
      {{ SC_(-36.434917449951171875), SC_(-0.4013604158054956102381643294616861600937e-17) }}, 
      {{ SC_(-36.22989654541015625), SC_(-0.4954070919347881798661389820765284703293e-17) }}, 
      {{ SC_(-36.151371002197265625), SC_(-0.5370115748619942846995056236200542722029e-17) }}, 
      {{ SC_(-36.0314483642578125), SC_(-0.607395305918129149416531788551080247298e-17) }}, 
      {{ SC_(-35.710315704345703125), SC_(-0.8447444058571321223562848170132272760574e-17) }}, 
      {{ SC_(-35.3704376220703125), SC_(-0.1197781809600591211033914907221945799548e-16) }}, 
      {{ SC_(-35.097530364990234375), SC_(-0.1585533750794002114788183801172421930711e-16) }}, 
      {{ SC_(-35.032459259033203125), SC_(-0.1695197166162417180772352306691754347417e-16) }}, 
      {{ SC_(-34.819854736328125), SC_(-0.2109244705480778173400075610148135850665e-16) }}, 
      {{ SC_(-34.751312255859375), SC_(-0.2263224452346398759852695717206224969765e-16) }}, 
      {{ SC_(-34.3925018310546875), SC_(-0.3272986079708841109973691119640729899672e-16) }}, 
      {{ SC_(-34.054973602294921875), SC_(-0.4631254422748072673716271830348503655722e-16) }}, 
      {{ SC_(-33.990711212158203125), SC_(-0.4947724616135280674694624593161655499417e-16) }}, 
      {{ SC_(-33.597461700439453125), SC_(-0.7414940191228214696888223680604909022873e-16) }}, 
      {{ SC_(-33.57765960693359375), SC_(-0.756757300887760805540854651208858682068e-16) }}, 
      {{ SC_(-33.2384185791015625), SC_(-0.107294068831277583736449351876748813907e-15) }}, 
      {{ SC_(-33.01177215576171875), SC_(-0.1354864993921957916546792647862260697468e-15) }}, 
      {{ SC_(-32.66255950927734375), SC_(-0.1941093737430240934530108031230878545462e-15) }}, 
      {{ SC_(-32.613666534423828125), SC_(-0.204132772872516639905834010047613657569e-15) }}, 
      {{ SC_(-32.159946441650390625), SC_(-0.3257412136825485821320656994134128511202e-15) }}, 
      {{ SC_(-32.11270904541015625), SC_(-0.3419855833378806479533913787891698469742e-15) }}, 
      {{ SC_(-31.7786407470703125), SC_(-0.4825063941260257502369727213840286372208e-15) }}, 
      {{ SC_(-31.169464111328125), SC_(-0.9041208285654553216232000743485732341508e-15) }}, 
      {{ SC_(-30.8748321533203125), SC_(-0.1225142484842369432707212786481995255584e-14) }}, 
      {{ SC_(-29.9968280792236328125), SC_(-0.3031462122352020681576569789998943438361e-14) }}, 
      {{ SC_(-29.7701435089111328125), SC_(-0.3830838750986454571203218948391228454923e-14) }}, 
      {{ SC_(-29.4440135955810546875), SC_(-0.5364965948171210691720366951042121092755e-14) }}, 
      {{ SC_(-29.2779827117919921875), SC_(-0.6368731799234152625106787139014919307596e-14) }}, 
      {{ SC_(-28.374523162841796875), SC_(-0.1620330664359454781224975910217836859007e-13) }}, 
      {{ SC_(-28.049365997314453125), SC_(-0.2268099668304392203466560599584613615573e-13) }}, 
      {{ SC_(-27.112514495849609375), SC_(-0.5981365620673597072402185048412869627752e-13) }}, 
      {{ SC_(-26.877002716064453125), SC_(-0.7633855292124147317951832423188187154848e-13) }}, 
      {{ SC_(-26.688323974609375), SC_(-0.9282018389970155561367076378137998442654e-13) }}, 
      {{ SC_(-26.1038379669189453125), SC_(-0.1701256502901405065500817349298173344176e-12) }}, 
      {{ SC_(-25.6862545013427734375), SC_(-0.2623518232936666267503379731452152909371e-12) }}, 
      {{ SC_(-25.3806858062744140625), SC_(-0.3602510949927852845512603205232949953593e-12) }}, 
      {{ SC_(-24.812534332275390625), SC_(-0.6498766587291270315525780335102007560594e-12) }}, 
      {{ SC_(-24.6828327178955078125), SC_(-0.7436238775678827344102896240858028195429e-12) }}, 
      {{ SC_(-23.609222412109375), SC_(-0.2270985496456140144232209569165697838238e-11) }}, 
      {{ SC_(-23.6052227020263671875), SC_(-0.2280458712546087199917148252497757574451e-11) }}, 
      {{ SC_(-23.212253570556640625), SC_(-0.3433205132674812376797712986415901957608e-11) }}, 
      {{ SC_(-22.38077545166015625), SC_(-0.8166398479320291904581660909155149328026e-11) }}, 
      {{ SC_(-22.17484283447265625), SC_(-0.1012326926235613489340088549168765113258e-10) }}, 
      {{ SC_(-22.028961181640625), SC_(-0.1178767187524946251357575066537303513673e-10) }}, 
      {{ SC_(-21.93953704833984375), SC_(-0.1294076260343429420577210021644224166493e-10) }}, 
      {{ SC_(-21.6740932464599609375), SC_(-0.1707311450429202319800292418877066733455e-10) }}, 
      {{ SC_(-21.4142551422119140625), SC_(-0.2239660671546579826122524352899183509804e-10) }}, 
      {{ SC_(-21.07315826416015625), SC_(-0.31989140498942794678382607273845334638e-10) }}, 
      {{ SC_(-20.9816799163818359375), SC_(-0.3519989253439093126729073010825611989496e-10) }}, 
      {{ SC_(-19.637241363525390625), SC_(-0.1438600620159160308817479271652146400346e-9) }}, 
      {{ SC_(-19.5384731292724609375), SC_(-0.1595610686595867225475531858139583145912e-9) }}, 
      {{ SC_(-19.3651943206787109375), SC_(-0.191371001872496098463574662692381338326e-9) }}, 
      {{ SC_(-18.90593719482421875), SC_(-0.30994031572235860524960759707349725788e-9) }}, 
      {{ SC_(-18.5577068328857421875), SC_(-0.4469016992114872271994190582757178616282e-9) }}, 
      {{ SC_(-17.3267612457275390625), SC_(-0.1633711779868352920783956469994975258958e-8) }}, 
      {{ SC_(-17.0185108184814453125), SC_(-0.2261792263181589044734075605962911166714e-8) }}, 
      {{ SC_(-16.78955841064453125), SC_(-0.2880510330832347302622379645025972070067e-8) }}, 
      {{ SC_(-16.1016254425048828125), SC_(-0.596294305040922450573339753675973857866e-8) }}, 
      {{ SC_(-15.76634502410888671875), SC_(-0.8505935450884228183463975203958420779551e-8) }}, 
      {{ SC_(-15.17945194244384765625), SC_(-0.1585549103627994633875481186154489551696e-7) }}, 
      {{ SC_(-15.11905670166015625), SC_(-0.1690611957957755240799660289020897272965e-7) }}, 
      {{ SC_(-13.43068981170654296875), SC_(-0.1022584513231563674448689979341186149526e-6) }}, 
      {{ SC_(-12.91650867462158203125), SC_(-0.1773761262859971060164899581342656864029e-6) }}, 
      {{ SC_(-12.575832366943359375), SC_(-0.255687274145036875029313903922532225666e-6) }}, 
      {{ SC_(-12.5575695037841796875), SC_(-0.2607537477649603990782583543108160730844e-6) }}, 
      {{ SC_(-11.91432666778564453125), SC_(-0.5210749882067263449474065372193218810935e-6) }}, 
      {{ SC_(-11.5017871856689453125), SC_(-0.8134101131665215640713025641914718088437e-6) }}, 
      {{ SC_(-11.395236968994140625), SC_(-0.91272723045117483696197441691774343853e-6) }}, 
      {{ SC_(-11.31745433807373046875), SC_(-0.9928537403218690168906979956279759632219e-6) }}, 
      {{ SC_(-11.19613552093505859375), SC_(-0.1132191013156966403507410220532861997662e-5) }}, 
      {{ SC_(-10.80203342437744140625), SC_(-0.1735824908097239014329439735951592857174e-5) }}, 
      {{ SC_(-10.257659912109375), SC_(-0.3138251672181765729003432862510751688375e-5) }}, 
      {{ SC_(-10.04949092864990234375), SC_(-0.3938286114079258742139622090231880229156e-5) }}, 
      {{ SC_(-8.15095806121826171875), SC_(-0.318435308755980338774238163595618232826e-4) }}, 
      {{ SC_(-8.02857112884521484375), SC_(-0.3648660193419818119566325214639226953631e-4) }}, 
      {{ SC_(-7.94337558746337890625), SC_(-0.4011732556063931089384872957189354164538e-4) }}, 
      {{ SC_(-7.397450923919677734375), SC_(-0.7385058450049667092943216183158760353767e-4) }}, 
      {{ SC_(-7.257321834564208984375), SC_(-0.8643407707350383467623358242945344658293e-4) }}, 
      {{ SC_(-6.85502719879150390625), SC_(-0.0001360233225396037741570065066289193367288) }}, 
      {{ SC_(-6.844749927520751953125), SC_(-0.0001376130697072288547351049358728336878462) }}, 
      {{ SC_(-6.56009578704833984375), SC_(-0.0001900005993505645179619309041336139866346) }}, 
      {{ SC_(-6.1387615203857421875), SC_(-0.0003071516884020679259927871076238348137779) }}, 
      {{ SC_(-6.02390766143798828125), SC_(-0.0003503420375785161458178656827678832632704) }}, 
      {{ SC_(-5.801117420196533203125), SC_(-0.0004525783807737199298571674150953465181097) }}, 
      {{ SC_(-5.5370635986328125), SC_(-0.0006139802161619321096305734620234110760157) }}, 
      {{ SC_(-5.039572238922119140625), SC_(-0.001096214284474157003983248247338271233381) }}, 
      {{ SC_(-4.60668182373046875), SC_(-0.00182646403775848961256251726233316613562) }}, 
      {{ SC_(-3.606259822845458984375), SC_(-0.006113092244150501182759223098480467043372) }}, 
      {{ SC_(-3.5703563690185546875), SC_(-0.006389725283693163413106729641577233598271) }}, 
      {{ SC_(-3.4518375396728515625), SC_(-0.007398826328864287868299387508442295495418) }}, 
      {{ SC_(-2.544478893280029296875), SC_(-0.02349896621151128636921912021857515353106) }}, 
      {{ SC_(-2.0270683765411376953125), SC_(-0.04710549033253332417891459635198730441661) }}, 
      {{ SC_(-1.74664974212646484375), SC_(-0.06982224065679792018629296005666623745408) }}, 
      {{ SC_(-1.73811972141265869140625), SC_(-0.07067947912193223977231133182821733641521) }}, 
      {{ SC_(-1.30539000034332275390625), SC_(-0.1343263664730872765772106823412265341571) }}, 
      {{ SC_(-0.9855175018310546875), SC_(-0.224789849918404400892777170618030689004) }}, 
      {{ SC_(-0.765717029571533203125), SC_(-0.3306204965891935899584519691640732251379) }}, 
      {{ SC_(-0.440425574779510498046875), SC_(-0.6391103091578925546980910928718730805524) }}, 
      {{ SC_(0.1690093176520690576580818742513656616211e-8), SC_(-19.62126650890371652595295530979865095775) }}, 
      {{ SC_(0.2114990849122477811761200428009033203125e-8), SC_(-19.39699968409704501608143944417902979644) }}, 
      {{ SC_(0.7099628440698779741069301962852478027344e-8), SC_(-18.18600771456330899529400229563313464444) }}, 
      {{ SC_(0.136718796284185373224318027496337890625e-7), SC_(-17.5307090168393574784921913178898385982) }}, 
      {{ SC_(0.1679341288252089725574478507041931152344e-7), SC_(-17.32506343605589965123585723923677953622) }}, 
      {{ SC_(0.586768322818898013792932033538818359375e-7), SC_(-16.07400514447660812399260402134573702052) }}, 
      {{ SC_(0.1140460881288163363933563232421875e-6), SC_(-15.40944740947244982567362347512857196391) }}, 
      {{ SC_(0.1455586016163579188287258148193359375e-6), SC_(-15.16547126071097956584839542123919818808) }}, 
      {{ SC_(0.38918477685001562349498271942138671875e-6), SC_(-14.18199554726483978034167263996676840479) }}, 
      {{ SC_(0.623782625552848912775516510009765625e-6), SC_(-13.71024759706876242023883975750942755915) }}, 
      {{ SC_(0.104669607026153244078159332275390625e-5), SC_(-13.1926552429023750061675349060182474459) }}, 
      {{ SC_(0.2951089072666945867240428924560546875e-5), SC_(-12.15611766257365306019177885908916324814) }}, 
      {{ SC_(0.4877083483734168112277984619140625e-5), SC_(-11.65374262154606280170522244483307812283) }}, 
      {{ SC_(0.9066634447663091123104095458984375e-5), SC_(-11.03368469534678539610212344978815972353) }}, 
      {{ SC_(0.2360353755648247897624969482421875e-4), SC_(-10.07687469212656789087127871765075953034) }}, 
      {{ SC_(0.60817910707555711269378662109375e-4), SC_(-9.130349744630693613333257072114132620679) }}, 
      {{ SC_(0.000119476739200763404369354248046875), SC_(-8.45505371136981670609925548596536076898) }}, 
      {{ SC_(0.0002437086659483611583709716796875), SC_(-7.742077649645587806911765144483417757553) }}, 
      {{ SC_(0.00047970912419259548187255859375), SC_(-7.064635197452612847888578571036009517596) }}, 
      {{ SC_(0.000960788573138415813446044921875), SC_(-6.369579496036524745416341422949188673429) }}, 
      {{ SC_(0.00113048148341476917266845703125), SC_(-6.206765179529281495180879269354516246991) }}, 
      {{ SC_(0.0033707791008055210113525390625), SC_(-5.112022087485498560545602301598797005544) }}, 
      {{ SC_(0.007697627879679203033447265625), SC_(-4.281914933633107042159905427812436577356) }}, 
      {{ SC_(0.0154774188995361328125), SC_(-3.575619984475573663157136373699830467351) }}, 
      {{ SC_(0.0305807329714298248291015625), SC_(-2.879353318645655463312010631432614581285) }}, 
      {{ SC_(0.0346831791102886199951171875), SC_(-2.749298553683104560876527875763233907) }}, 
      {{ SC_(0.09283597767353057861328125), SC_(-1.704669515752701009603290162653889150725) }}, 
      {{ SC_(0.16360938549041748046875), SC_(-1.062505460428854260642631229015752036299) }}, 
      {{ SC_(0.22476322948932647705078125), SC_(-0.6774408343494534677895972717532955476869) }}, 
      {{ SC_(0.37880718708038330078125), SC_(0.02441666034110163309027907713654447093795) }}, 
      {{ SC_(0.4500701129436492919921875), SC_(0.2850997481756199579143134375351571168498) }}, 
      {{ SC_(0.64851474761962890625), SC_(0.9150076958911796894005017309253737142643) }}, 
      {{ SC_(0.872161686420440673828125), SC_(1.546602463133721778520197846604188825167) }}, 
      {{ SC_(1.14188635349273681640625), SC_(2.282017713054334977384465917433486481954) }}, 
      {{ SC_(1.632969379425048828125), SC_(3.708022196201172208181850369303918535594) }}, 
      {{ SC_(1.91524684429168701171875), SC_(4.647560468822983657335378269935274858252) }}, 
      {{ SC_(2.0095670223236083984375), SC_(4.989664796356000084558864930434693816234) }}, 
      {{ SC_(2.061771869659423828125), SC_(5.186049765719297790031932942365080982976) }}, 
      {{ SC_(2.2234554290771484375), SC_(5.829455392510293560943895777670731465053) }}, 
      {{ SC_(3.391320705413818359375), SC_(12.93581868697820390884888173217329392277) }}, 
      {{ SC_(3.63258075714111328125), SC_(15.24140806012294293304307663205345607658) }}, 
      {{ SC_(3.874083042144775390625), SC_(17.9905574004211871523525648227022806255) }}, 
      {{ SC_(3.9647958278656005859375), SC_(19.15663585397278189871759282735891458668) }}, 
      {{ SC_(4.820046901702880859375), SC_(35.20942043634765130040913234375925316531) }}, 
      {{ SC_(4.839860439300537109375), SC_(35.7230453208944376116432625721437408942) }}, 
      {{ SC_(5.3509044647216796875), SC_(52.22020521530953938550833436236144368121) }}, 
      {{ SC_(5.40289783477783203125), SC_(54.31243085873860477879662300914122221072) }}, 
      {{ SC_(5.524809360504150390625), SC_(59.58055115475630923207417956895030150463) }}, 
      {{ SC_(5.60483837127685546875), SC_(63.3358979487388193548024404586957936219) }}, 
      {{ SC_(5.655277252197265625), SC_(65.83272358924251841359208893617229420928) }}, 
      {{ SC_(5.68704509735107421875), SC_(67.45933093217862071244254216727784222832) }}, 
      {{ SC_(6.457447052001953125), SC_(123.4702296391656695506519753815867966569) }}, 
      {{ SC_(8.01086139678955078125), SC_(444.4463643880764930507024304168884617662) }}, 
      {{ SC_(8.13864803314208984375), SC_(495.3101709262324392110450657667108532755) }}, 
      {{ SC_(8.28261566162109375), SC_(559.877848810511434189052045218975505771) }}, 
      {{ SC_(8.387729644775390625), SC_(612.4581525328497943613664298891423815016) }}, 
      {{ SC_(8.7326412200927734375), SC_(823.599445125107912460255698424832715259) }}, 
      {{ SC_(8.89971637725830078125), SC_(951.4942058135830875156789370724711488375) }}, 
      {{ SC_(9.21766567230224609375), SC_(1254.116584663167251806959698506292298412) }}, 
      {{ SC_(10.12511348724365234375), SC_(2783.932169928304521372514424737213979338) }}, 
      {{ SC_(10.15696430206298828125), SC_(2863.594026810931459246318070217071739042) }}, 
      {{ SC_(10.19370746612548828125), SC_(2958.379138016360344099887177971538047866) }}, 
      {{ SC_(10.19426441192626953125), SC_(2959.840173454726579315814039625058033301) }}, 
      {{ SC_(10.4695987701416015625), SC_(3780.023943205871070531887511694330145346) }}, 
      {{ SC_(10.48462009429931640625), SC_(3830.912593094958387366502243352980495425) }}, 
      {{ SC_(11.4095668792724609375), SC_(8773.100258415416694826189142702383416451) }}, 
      {{ SC_(11.7713222503662109375), SC_(12161.33897998932776399014133107556617305) }}, 
      {{ SC_(12.4603786468505859375), SC_(22729.88062534874311051752965324633319716) }}, 
      {{ SC_(12.57059955596923828125), SC_(25130.98763507991967701586529249834912407) }}, 
      {{ SC_(13.11301326751708984375), SC_(41251.55674345891428427980010586930742943) }}, 
      {{ SC_(13.7675037384033203125), SC_(75228.92803868848986122975671702709528184) }}, 
      {{ SC_(13.9052371978759765625), SC_(85400.1662872705358542582248024368153919) }}, 
      {{ SC_(14.3790493011474609375), SC_(132224.1847370047667808930523187693328728) }}, 
      {{ SC_(14.3794498443603515625), SC_(132273.1335203298191314772732228745972998) }}, 
      {{ SC_(15.21062469482421875), SC_(285682.5599867407331192380971834146771446) }}, 
      {{ SC_(15.39539432525634765625), SC_(339189.3027111421620231430296710100618608) }}, 
      {{ SC_(16.218013763427734375), SC_(729907.8872092321790234225457781718572718) }}, 
      {{ SC_(16.46546173095703125), SC_(919706.2433779946775124389017819374115907) }}, 
      {{ SC_(17.7649173736572265625), SC_(3108879.230687753723076805660417797528995) }}, 
      {{ SC_(18.23960113525390625), SC_(4858737.11952045506522062926385708137311) }}, 
      {{ SC_(18.4260616302490234375), SC_(5791494.941827564738522268163850830865472) }}, 
      {{ SC_(19.012279510498046875), SC_(10066932.15321395806087810278623274756541) }}, 
      {{ SC_(19.5595188140869140625), SC_(16883605.29408456961771231663180943490866) }}, 
      {{ SC_(20.37397003173828125), SC_(36508755.03776723110298560035691974974617) }}, 
      {{ SC_(20.835704803466796875), SC_(56575951.205609704704636343530031541064) }}, 
      {{ SC_(21.0944309234619140625), SC_(72332387.61173328702549768015323808037801) }}, 
      {{ SC_(21.9486980438232421875), SC_(162986366.6628523568138908187268486831292) }}, 
      {{ SC_(22.0607814788818359375), SC_(181342019.5679948669381801941271758479043) }}, 
      {{ SC_(22.1025676727294921875), SC_(188703736.1360623611074418193171278225304) }}, 
      {{ SC_(22.1314754486083984375), SC_(193971208.5963560967150675933295824773472) }}, 
      {{ SC_(22.6131420135498046875), SC_(306960930.053725589282112731051688195145) }}, 
      {{ SC_(22.9966068267822265625), SC_(442531056.6008858180372506333673348776581) }}, 
      {{ SC_(24.66086578369140625), SC_(2172219893.769243704085432245669500194727) }}, 
      {{ SC_(24.7471675872802734375), SC_(2359372003.318650065162623018506525353893) }}, 
      {{ SC_(24.7672977447509765625), SC_(2405300409.260463112199179923485274897776) }}, 
      {{ SC_(24.78017425537109375), SC_(2435147794.700459281996413056218750490234) }}, 
      {{ SC_(24.831577301025390625), SC_(2558042555.796109988805685451913765393216) }}, 
      {{ SC_(24.9495487213134765625), SC_(2864104017.927884220619778105722242253745) }}, 
      {{ SC_(25.8135986328125), SC_(6558254256.348564813851988511155677431286) }}, 
      {{ SC_(26.431148529052734375), SC_(11865100527.11967913666447024180657659641) }}, 
      {{ SC_(26.475616455078125), SC_(12382894374.47640125042051702147914482717) }}, 
      {{ SC_(26.8984375), SC_(18589906285.97139709477775311556771661975) }}, 
      {{ SC_(27.6351680755615234375), SC_(37758334087.66944768183509564350686344903) }}, 
      {{ SC_(27.6650714874267578125), SC_(38860718906.05169447986846371460827946851) }}, 
      {{ SC_(28.030132293701171875), SC_(55224345285.73183315482360024631420661039) }}, 
      {{ SC_(28.1774234771728515625), SC_(63640104036.92648906241078382739179720716) }}, 
      {{ SC_(28.771076202392578125), SC_(112755629580.1567007685754818929698465233) }}, 
      {{ SC_(29.2542781829833984375), SC_(179670592771.6875712257676967047727294651) }}, 
      {{ SC_(29.84228515625), SC_(316865442957.5609324434506204080682970604) }}, 
      {{ SC_(29.9650173187255859375), SC_(356720167837.8059821256007389978942158479) }}, 
      {{ SC_(30.60785675048828125), SC_(663668224048.0604218612696926330408705931) }}, 
      {{ SC_(30.651767730712890625), SC_(692430279700.9637790480873609641395475303) }}, 
      {{ SC_(31.47119903564453125), SC_(1528910755990.844994280853960653895757449) }}, 
      {{ SC_(31.744571685791015625), SC_(1991673673982.885396571525113897855042645) }}, 
      {{ SC_(32.2966766357421875), SC_(3398181411672.422126614376199484878709082) }}, 
      {{ SC_(32.49350738525390625), SC_(4111498043870.037918808870011846450846812) }}, 
      {{ SC_(32.639377593994140625), SC_(4735210781514.282917532917045901722362452) }}, 
      {{ SC_(32.9102020263671875), SC_(6155269461572.004859718923506587585651898) }}, 
      {{ SC_(33.015533447265625), SC_(6816439946334.964794674640603518324460658) }}, 
      {{ SC_(33.292026519775390625), SC_(8910343016135.140885096036479635757392035) }}, 
      {{ SC_(33.351413726806640625), SC_(9438137404966.366739297549042509103959184) }}, 
      {{ SC_(33.790431976318359375), SC_(14443862666819.21046289715593905528182097) }}, 
      {{ SC_(33.866344451904296875), SC_(15546956543575.59764405635272615745868862) }}, 
      {{ SC_(34.012500762939453125), SC_(17913865016638.12842343852721911357435736) }}, 
      {{ SC_(34.20684814453125), SC_(21629122436899.19912288305015863841369024) }}, 
      {{ SC_(35.130886077880859375), SC_(53015183051332.74153203541356793785468028) }}, 
      {{ SC_(35.24015045166015625), SC_(58947101093536.87223820738247177154640853) }}, 
      {{ SC_(35.67874908447265625), SC_(90241306347642.26414493832961429071231867) }}, 
      {{ SC_(35.70839691162109375), SC_(92877271582193.34830869185118876551411853) }}, 
      {{ SC_(37.142803192138671875), SC_(374322570986670.3197355366942794241040052) }}, 
      {{ SC_(37.295734405517578125), SC_(434336543053163.6784396158427358728630635) }}, 
      {{ SC_(37.337249755859375), SC_(452229579706005.3198360961998657288335433) }}, 
      {{ SC_(37.371295928955078125), SC_(467452657592235.4557742032788566543129601) }}, 
      {{ SC_(37.47199249267578125), SC_(515545372809301.8307905963516087180550462) }}, 
      {{ SC_(37.700786590576171875), SC_(644036634222999.9230954385992851671021201) }}, 
      {{ SC_(37.77214813232421875), SC_(690331189582367.0242854882027008973993238) }}, 
      {{ SC_(37.7916412353515625), SC_(703546341004539.6440063503740195080075798) }}, 
      {{ SC_(38.007534027099609375), SC_(867977923035967.2387116719471097584367879) }}, 
      {{ SC_(38.030849456787109375), SC_(887892682109427.8216437485269424411635003) }}, 
      {{ SC_(38.232257843017578125), SC_(1080118946394155.640540236541909448482468) }}, 
      {{ SC_(38.828411102294921875), SC_(1929604067639860.142261254221961073466133) }}, 
      {{ SC_(38.8993072509765625), SC_(2067490868399521.448714428128264044795958) }}, 
      {{ SC_(39.070796966552734375), SC_(2443188466949830.286454990607186034125934) }}, 
      {{ SC_(39.57132720947265625), SC_(3977896133471904.309030036870273146195475) }}, 
      {{ SC_(39.619602203369140625), SC_(4169413741026091.435196275993524526107061) }}, 
      {{ SC_(39.903354644775390625), SC_(5496968390256242.123534199929484292088181) }}, 
      {{ SC_(40.292484283447265625), SC_(8031404394724528.542925073441994364789595) }}, 
      {{ SC_(40.337055206298828125), SC_(8387940643235804.328777240761144315540951) }}, 
      {{ SC_(40.40936279296875), SC_(9000350988468569.862069911874242513693811) }}, 
      {{ SC_(40.486545562744140625), SC_(9703503769049494.903270793598303590559637) }}, 
      {{ SC_(40.58036041259765625), SC_(10632608216710854.46031088764839485644682) }}, 
      {{ SC_(40.839870452880859375), SC_(13693091147862452.41874314869980290347395) }}, 
      {{ SC_(41.391147613525390625), SC_(23439146134369609.98587928723498036090512) }}, 
      {{ SC_(41.850940704345703125), SC_(36703294479064600.3832020868783140575162) }}, 
      {{ SC_(42.4788970947265625), SC_(67731301681578920.49039567895447521625383) }}, 
      {{ SC_(43.331455230712890625), SC_(155669602636333053.4786944018929963653098) }}, 
      {{ SC_(43.404224395751953125), SC_(167132241928819035.0710856728527709620153) }}, 
      {{ SC_(43.8334197998046875), SC_(254143262583491699.1980601913565298527589) }}, 
      {{ SC_(43.9896087646484375), SC_(296024739641759806.6894125116837989457761) }}, 
      {{ SC_(44.14626312255859375), SC_(344969417880314064.475422911828132537173) }}, 
      {{ SC_(44.89459991455078125), SC_(716642754835341877.2986625908564001827266) }}, 
      {{ SC_(45.55641937255859375), SC_(1368424686960668756.908114295234155840218) }}, 
      {{ SC_(45.622142791748046875), SC_(1459228779377576203.085179194127347039233) }}, 
      {{ SC_(45.96717071533203125), SC_(2044647179130784910.065675826506375503182) }}, 
      {{ SC_(46.443317413330078125), SC_(3257069147351952822.406316784082908654148) }}, 
      {{ SC_(46.62737274169921875), SC_(3899455212627022627.757193164190203742303) }}, 
      {{ SC_(47.999355316162109375), SC_(14926880987843627550.42423425846631056877) }}, 
      {{ SC_(49.637111663818359375), SC_(74190413685387077283.04485547837473387867) }}, 
      {{ SC_(49.81011962890625), SC_(87890252389194795154.44680392696975525721) }}, 
      {{ SC_(50.171234130859375), SC_(125189140534515913902.5259763391614688736) }}, 
      {{ SC_(50.383525848388671875), SC_(154131408309808097686.7891755712917358669) }}, 
      {{ SC_(50.46710968017578125), SC_(167284637436075321503.8911970981891929543) }}, 
      {{ SC_(50.471343994140625), SC_(167980083475835196141.8258748379299905807) }}, 
      {{ SC_(50.7309112548828125), SC_(216626578190231872367.3411388285205467896) }}, 
      {{ SC_(50.891300201416015625), SC_(253494280682248147653.5031137670581769109) }}, 
      {{ SC_(51.29622650146484375), SC_(376974396494639297221.5916323256511307768) }}, 
      {{ SC_(52.0242156982421875), SC_(769533307813336085464.2719431240758770955) }}, 
      {{ SC_(52.21900177001953125), SC_(931463445412117009569.997805462678793371) }}, 
      {{ SC_(52.4724273681640625), SC_(1194213241460405145426.923208285103882948) }}, 
      {{ SC_(52.739253997802734375), SC_(1551371845141512428417.754279321277408047) }}, 
      {{ SC_(52.741176605224609375), SC_(1554299590225018307998.020329038078465699) }}, 
      {{ SC_(53.40814208984375), SC_(2989698064310689472929.903511572929914131) }}, 
      {{ SC_(54.5244293212890625), SC_(8938496865444328223663.418183347060066178) }}, 
      {{ SC_(55.05193328857421875), SC_(15000102942849475726352.24634597020497441) }}, 
      {{ SC_(55.28836822509765625), SC_(18918195096476420185424.79716369248547301) }}, 
      {{ SC_(55.32575225830078125), SC_(19625295432594734639694.04077946718413513) }}, 
      {{ SC_(55.522052764892578125), SC_(23795829974930383969706.74411638885122467) }}, 
      {{ SC_(55.544170379638671875), SC_(24318128427099146738245.91342763630756375) }}, 
      {{ SC_(55.57183837890625), SC_(24987672558936599326235.83821092811506408) }}, 
      {{ SC_(55.808788299560546875), SC_(31531809737095643566486.71781327383155317) }}, 
      {{ SC_(56.137737274169921875), SC_(43552095758129714470140.32600682101217921) }}, 
      {{ SC_(56.146297454833984375), SC_(43919686479374955504528.98148221455056972) }}, 
      {{ SC_(56.446441650390625), SC_(58972731376406161145451.87899710728216492) }}, 
      {{ SC_(56.5754547119140625), SC_(66937712106290641632239.78290159424299056) }}, 
      {{ SC_(56.765209197998046875), SC_(80648977731394081623112.8051042421861491) }}, 
      {{ SC_(57.47022247314453125), SC_(161184177439288421438465.5484877575634735) }}, 
      {{ SC_(57.791820526123046875), SC_(221066403776152634685122.7495432888528563) }}, 
      {{ SC_(57.92206573486328125), SC_(251241864908534403966454.9934420615252414) }}, 
      {{ SC_(58.059658050537109375), SC_(287606300821348197823323.3455461108172774) }}, 
      {{ SC_(58.620555877685546875), SC_(499047878771232722946891.2015515727402121) }}, 
      {{ SC_(58.721736907958984375), SC_(551216418687710616233343.712210604071037) }}, 
      {{ SC_(58.73737335205078125), SC_(559751492456295202734141.0778013286664605) }}, 
      {{ SC_(59.21694183349609375), SC_(896756596017748427943431.7704197691518272) }}, 
      {{ SC_(59.3475341796875), SC_(1019568455497745443792447.961272554810421) }}, 
      {{ SC_(59.574817657470703125), SC_(1274778904679711262832523.146694528881756) }}, 
      {{ SC_(59.610748291015625), SC_(1320604762679106118330023.701104305685706) }}
   }};

