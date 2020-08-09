let input, button, canvas;
let nameInput;
let fontx, fonty;
let outputScript="ghee";
var gridOffsetx;
var gridOffsety;
let num1;
let num2;

let sprites = [];

let gridCreated = false;
let copyFlag=false;
class Rectangle {
  constructor(x, y, filled,row,column) {
    this.x = x;
    this.y = y;
    this.row=row;
    this.column=column;
    this.filled = filled;
  }
  draw() {
    if (this.filled)
      fill(0);
    else
      fill(220);
    rect(this.x, this.y, 10, 10);
  }
}

function setup() {
  canvas = createCanvas(0, 0);
  input = createInput();
  nameInput = createInput();
  nameInput.position(600, 80);
  input.position(400, 80);
  canvas.position(600, 150);
  rectMode(RADIUS);
  button=createButton("copy");
  button.mousePressed(copyToClipboard);
}

function draw() {
  background(220);
  if (tryReadDimensions()&&gridCreated&&!copyFlag) {
    
    fill(255, 0, 0);
    gridOffsetx = (fontx / num1) / 2;
    gridOffsety = (fonty / num2) / 2;
   // ellipse(snap(mouseX, gridOffsetx, fontx / num1), snap(mouseY, gridOffsety, fonty / num2), 5, 5);
   
    for (let i = 0; i < sprites.length; i++) {
      sprites[i].draw();
    }
    
    outputScript="//"+nameInput.value()+"\n";
    if(num2>0&&num1>0)
    for(let i=0;i<num2;i++)
    {
      //sprites[i].filled=true;
       let outli="0b"
       for(let j=0;j<num1;j++)
      {
        
        //locate sprites on that point
        for (let k = 0; k < sprites.length; k++) {
         if(sprites[k].row==j&&sprites[k].column==i)
        //  print("x%d y%d j%d i%d",sprites[k].x,sprites[k].y,j,i);
          
          if(sprites[k].filled)
            outli+="1";
          
          else
            outli+="0";
    }
        
      
      }
       outputScript+=outli+","+"\n";
    }
    rect(snap(mouseX,gridOffsetx,fontx/num1),snap(mouseY,gridOffsety,fonty/num2),7,7);   
  changeText(outputScript);

  } else {
    gridCreated = false;
    print("Invalid format, enter #x#");
  }
}
function drawGrid(){
  // Draw grid
    stroke(0);
    fill(0);
    var l = 0;
    while (l < height) {
      line(0, l, width, l);
      l += fontx / num1;
    }
    l = 0;
    while (l < width) {
      line(l, 0, l, height);
      l += fonty / num2;
    }
}
function tryReadDimensions() {
  try {
    num1 = parseInt(splitTokens(input.value(), 'x')[0],10);
    num2 = parseInt(splitTokens(input.value(), 'x')[1],10);
    fontx = num1 * 20;
    fonty = num2 * 20;

  } catch (e) {
    return false;
  }
  return true;
}

function keyPressed() {
  if (keyCode === RETURN)
  {resize(fontx, fonty);
   sprites = [];
   if(num2>0&&num1>0)
  for(let i=0;i<num1;i++)
    for(let j=0;j<num2;j++)
    {
      let ii=i;
      let jj=j;
      if(ii!=0)
        ii=(fontx/i);
      if(jj!=0)
        jj=(fonty/j);
     sprites.push(new Rectangle(i*20+10, j*20+10, false,i,j));
    }
   gridCreated = true;
}
}

function mousePressed() {
  //  if(sprites.count>0){

  //    sprites.forEach(function(entry) {
  //     var singleObj = {};
  //     singleObj['type'] = 'vehicle';
  //     singleObj['value'] = entry;
  //     listOfObjects.push(singleObj);
  // });

  //    }
  //   else{


  //   }
  if (gridCreated) {
   
     
      let snappedPointx = snap(mouseX, gridOffsetx, fontx / num1);
      let snappedPointy = snap(mouseY, gridOffsety, fonty / num2);
      //print("snapx %d snapy %d,mousex %d.mousey %d,width %d,height%d",snappedPointx,snappedPointy,mouseX,mouseY,width,height);
   
      for (let i = 0; i < sprites.length; i++) {
       
       // print("spritex %d spritey %d,",sprites[i].x,sprites[i].y);
        if (sprites[i].x == snappedPointx && sprites[i].y == snappedPointy ) {
          if(sprites[i].filled)
            sprites[i].filled = false;
          else{
            sprites[i].filled = true;
          }
          break;
        }
      }
     

      
    } 

  
}
function changeText(text){
  document.getElementById("outputText").innerHTML = text;
}
function resize(x, y) {
  resizeCanvas(x, y);
}
function copyToClipboard(){
  copyFlag=true;
   let outPar=document.getElementById("outputText") ;
  outPar.select();
  document.execCommand('copy');
  print("copied");
  copyFlag=false;
}
function snap(op, offset, grid) {
  // subtract offset (to center lines)
  // divide by grid to get row/column
  // round to snap to the closest one
  var cell = Math.round((op - offset) / grid);
  // multiply back to grid scale
  // add offset to center
  return cell * grid + offset;
}