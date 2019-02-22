var canvas = document.getElementById("canvas");
var ctx = canvas.getContext("2d");
var ratio = window.devicePixelRatio;
canvas.width = window.innerWidth*ratio;
canvas.height = window.innerHeight*ratio;

window.onresize=function() {
  canvas.width = window.innerWidth*ratio;
  canvas.height = window.innerHeight*ratio;
  _dim(canvas.width,canvas.height);
  ctx.font = '30px Arial bold';
  ctx.imageSmoothingEnabled = false;
};

var offscreen = document.createElement('canvas');
offscreen.width=2500;
offscreen.height=800;
var off = offscreen.getContext("2d");

function color(c) {
  c=c.toString(16);
  while(c.length<6)
    c='0'+c;
   c='#'+c;
  return c;}

ctx.font = '30px Arial bold';
ctx.imageSmoothingEnabled = false;

var requestId;
var pr=0;

canvas.onpointerdown = function(e) {
  _inputPt(e.pageX,e.pageY,1);
}
canvas.onpointerup = function(e) {
  _inputPt(e.pageX,e.pageY,0);
}
canvas.onpointercancel = function(e) { 
  alert("oof");
}
window.onkeydown = function(e){
  _input(e.keyCode,1);
};
window.onkeyup=function(e){
  _input(e.keyCode,0);
};

// bg and GUI images
var folders = ["","GUI","Items","Mario"];
var src = [
  // bg and GUI images
  [9797,248],
  [109],
  [196,1],
  //Char images
  [10063,10066,10068,10073,10075,10081,10083,10086,1021,1029,1031,1033,1035,1037,1039,1041,1045,1047,1049,1051,1053,1055,1057,1059,1061,1063,10645,10647,1065,1067,1069,1073,1076,1078,1080,1082,1084,1086,1088,1090,1094,1114,1119,1121,1130,1134,1136,1140,1142,1145,1147,1151,1153,1158,1160,1162,1164,1166,1168,1170,1172,1183,1186,1190,1195,1197,1200,1202,1204,1206,1208,1210,1213,1218,1222,1242,1244,1246,1248,1250,1252,1254,1264,1266,1269,1271,1273,1276,1278,1280,1282,1285,1288,1292,1312,1314,1316,1318,1320,1322,1324,1326,1334,1336,1339,1341,1343,1345,1347,1349,1351,1353,1368,1375,1398,1400,1402,1404,1406,1408,1410,1412,1420,1422,1425,1427,1429,1432,1434,1437,1443,1449,1452,1457,1459,1461,1463,1468,1471,1476,1481,1483,1486,1488,1490,1492,1494,1496,1513,1515,1517,1519,1521,1523,1530,1532,1534,1536,1538,1540,1542,1544,1548,1550,1552,1554,1556,1558,1560,1562,1564,1569,1573,1576,1581,1586,1595,1600,1604,1606,1610,1612,1619,1622,1626,1628,1631,1633,1635,1649,1652,1655,1659,1661,1663,1665,1667,1669,1671,1673,1675,1677,1679,1681,1703,1705,1708,1710,1712,1714,1718,1720,1722,1724,350,359,361,363,365,367,369,371,376,378,391,396,437,465,467,578,581,599,605,615,775,9853,9855,9882,9904,9907,9910]
];

var src2flip = [1033,378];

var img = {};
for (var i=0; i<src.length; i++) {
  for (var j=0; j<src[i].length; j++) {
    img[src[i][j]] = new Image();
    img[src[i][j]].src = "images/" + folders[i] + "/" + src[i][j] +".png";
  }
}

// some images have a flipped version
var tcanvas = document.createElement('canvas');
var tctx = tcanvas.getContext("2d");
function flipImage(id) {
  img[id].onload = function() {
    tcanvas.width=img[id].width;
    tcanvas.height=img[id].height;
    tctx.scale(-1,1);
    tctx.drawImage(img[id],-img[id].width,0);
    img[20000+id] = new Image();
    img[20000+id].src = tcanvas.toDataURL("image/png");
  }
}
for (var i=0; i<src2flip.length; i++) {
  flipImage(src2flip[i]);
}

canvas.style.width='100%';
canvas.style.height='100%';
var textString = ""; 