

var direction;		//A to C:true ; C to A:false
var people = new Array(9);
var s2Able;		//判断船2是否有人
var s1Able;		//判断船1是否有人
var pInShip1;	//哪个人在船1上
var pInShip2;	//哪个人在船2上


function init(){
  var peoplenum = document.getElementById("texta").getAttribute("value")
  for (var i= 0; i < peoplenum; i++){
    
  }

  var peopleA = document.getElementById("A").getElementsByTagName("div");
  var ships   = document.getElementsByName("ship");
  var peopleC = document.getElementById("C").getElementsByTagName("div");
  var moveBtn = document.getElementById("btn");
  var newBtn  = document.getElementById("new");

  for(var i=0,len = peopleC.length; i < len; i++){
    peopleC[i].style.visibility="hidden";
  }
  s1Able=true;
  s2Able=true;
  direction=true;

  for (var i=0;i<9;i++)
  {
    people[i]=true;
  }

  //注册事件
  var len=peopleA.length;
  for(var j=0;j<len;j++){
    (function(m){
      peopleA[m].onclick = function(){
        if(direction)
          selectPeople(this,m+1);
      };
      peopleC[m].onclick = function(){
        if(!direction)
          selectPeople(this,m+10+1);
      };
    })(j);
  }

  ships[0].onclick=function(){
    quitShip(this,pInShip1);
    s1Able=true;
    pInShip1=0;
  };
  ships[1].onclick=function(){
    quitShip(this,pInShip2);
    s2Able=true;
    pInShip2=0;
  };
  moveBtn.onclick=function(){
    move();
  };
  newBtn.onclick=function(){
    window.location = window.location;
  };
}
function selectPeople(obj,move_num){
  var ships=document.getElementsByName("ship");
  if(s1Able){
    ships[0].innerHTML=obj.innerHTML;
    obj.style.visibility="hidden";
    s1Able=false;
    pInShip1=move_num;
    if(move_num>10)
      people[move_num-10]=!people[move_num-10];
    else
      people[move_num]=!people[move_num];
  }
  else if(s2Able){
    ships[1].innerHTML=obj.innerHTML;
    obj.style.visibility="hidden";
    s2Able=false;
    pInShip2=move_num;
    if(move_num>10)
      people[move_num-10]=!people[move_num-10];
    else
      people[move_num]=!people[move_num];
  }
  else{
    alert("船上最多两个人，已满!");
  }
}
function quitShip(obj,quitId){
  if(obj.innerHTML != ""){
    var peopleA=document.getElementById("A").getElementsByTagName("div");
    var peopleC=document.getElementById("C").getElementsByTagName("div");
    if(quitId > 10){
      peopleC[quitId-10-1].style.visibility="visible";
      people[quitId-10]=!people[quitId-10];
    }
    else{
      peopleA[quitId-1].style.visibility="visible";
      people[quitId]=!people[quitId];
    }
    obj.innerHTML="";
  }
}
function motherCheck(){
  if(people[1]==people[5])
  {
    if(people[4]!=people[1])
    {
      alert("妈妈打儿子1");
      return false;
    }
  }
  if(people[1]==people[6])
  {
    if(people[4]!=people[1])
    {
      alert("妈妈打儿子2");
      return false;
    }
  }
  return true;
}
function fatherCheck(){
  if(people[4]==people[2])
  {
    if(people[1]!=people[4])
    {
      alert("爸爸打女儿1");
      return false;
    }
  }
  if(people[4]==people[3])
  {
    if(people[1]!=people[4])
    {
      alert("爸爸打女儿2");
      return false;
    }
  }
  return true;
}
function policeCheck(){
  if(people[7]!=people[8])
  {
    for(var i=1;i<8;i++)
    {
      if(people[8]==people[i])
      {
        alert("犯人伤人");
        return false;
      }
    }
  }
  return true;
}
function atoc(peopleId){
  var peopleC=document.getElementById("C").getElementsByTagName("div");
  var ships=document.getElementsByName("ship");
  var tempId;
  if(peopleId > 10){
    tempId = peopleId - 10 -1;
  }
  else
    tempId = peopleId - 1;
  if(tempId >= 0)
    peopleC[tempId].style.visibility="visible";
  for(var i=0,len=ships.length;i<len;i++){
    ships[i].style.left = "170px";
    ships[i].innerHTML = "";
  }
}
function ctoa(peopleId){
  var peopleA=document.getElementById("A").getElementsByTagName("div");
  var ships=document.getElementsByName("ship");
  var tempId;
  if(peopleId > 10){
    tempId = peopleId - 10 -1;
  }
  else
    tempId = peopleId - 1;
  if(tempId >= 0)
    peopleA[tempId].style.visibility="visible";
  for(var i=0,len=ships.length;i<len;i++){
    ships[i].style.left = "-170px";
    ships[i].innerHTML = "";
  }
}
function move(){
  if(pInShip1==1 || pInShip1==4 || pInShip1==7 ||
    pInShip1==11 || pInShip1==14 || pInShip1==17 ||
    pInShip2==1 || pInShip2==4 || pInShip2==7 ||
    pInShip2==11 || pInShip2==14 || pInShip2==17
  )		//开动船只的人只能是爸爸妈妈或者是警察
  {
    if (motherCheck()&& fatherCheck() && policeCheck())
    {
      if(direction)
      {
        atoc(pInShip1);
        atoc(pInShip2);
        direction=false;
      }
      else
      {
        ctoa(pInShip1);
        ctoa(pInShip2);
        direction=true;
      }
      s1Able=s2Able=true;
      pInShip1=pInShip2=0;

      var peopleC=document.getElementById("C").getElementsByTagName("div");
      var result = true;
      for(var i=0,len=peopleC.length;i<len;i++){
        if(peopleC[i].style.visibility=="hidden"){
          result = false;
          break;
        }
      }
      if(result){
        alert("你真厉害！");
        window.location = window.location;
      }
    }
  }
  else
    alert("只有妈妈、爸爸和警察能撑船！");
}


window.onload = function(){
  init();
};
