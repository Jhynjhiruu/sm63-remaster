function _anim(timestamp) {
    setTimeout(function() { // tries to artificially limit fps
        _run(timestamp-pr);
        document.getElementById("fps").innerHTML="FPS: "+Math.round(1000/(timestamp-pr));
        pr=timestamp;
        requestId=requestAnimationFrame(_anim);
    },(1000/30-(timestamp-pr)));
}

function _drawRect(x,y,w,h,c) {ctx.fillStyle=color(c);ctx.fillRect(x,y,w,h);}
function _ctxLine(x1,y1,x2,y2,c) {ctx.strokeStyle=color(c);ctx.beginPath();ctx.moveTo(x1,y1);ctx.lineTo(x2,y2);ctx.stroke();ctx.closePath();}
function _drawImage(id,x,y,s) {ctx.drawImage(img[id],x,y,img[id].width*s,img[id].height*s);}
function _drawNum(a,x,y,c) {ctx.fillStyle=color(c);ctx.fillText(a,x,y);ctx.strokeStyle="#FFFFFF";ctx.strokeText(a,x,y);}

function _fmod(a,b) {return a%b;}
function _m_round(a) {return Math.round(a);}
function _m_floor(a) {return Math.floor(a);}
function _m_ceil(a) {return Math.ceil(a);}
function _m_abs(a) {return Math.abs(a);}
function _m_sin(a) {return Math.cos(a);}
function _m_cos(a) {return Math.cos(a);}
function _m_sqrt(a) {return Math.sqrt(a);}
function _m_atan2(a,b) {return Math.atan2(a,b);}

function _hitTestF(x,y) {
    var pixelData = off.getImageData(x,y,1,1).data;
    if (pixelData[3]>0)
        return true;
    else
        return false;
}
function _drawData() {ctx.drawImage(offscreen,0,0);} // draws to main canvas
function _reqDim() {_dim(canvas.width,canvas.height);} // request
function _reqImgW(id) {return img[id].width;}
function _reqImgH(id) {return img[id].height;}

function _beginPath() {off.beginPath();}
function _moveTo(x,y) {off.moveTo(x,y);}
function _lineTo(x,y) {off.lineTo(x,y);}
function _curveTo(a,b,c,d) {off.quadraticCurveTo(a,b,c,d);}
function _closePath() {off.closePath();}
function _fill(c) {off.fillStyle=color(c);off.fill();}
function _stroke() {off.stroke();}

function _addText(a) {
    textString+=String.fromCharCode(a);
}
function _logText() {
    console.log(textString);
    textString="";
}