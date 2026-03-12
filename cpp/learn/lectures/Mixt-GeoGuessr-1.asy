if(!settings.multipleView) settings.batchView=false;
settings.tex="pdflatex";
defaultfilename="Mixt-GeoGuessr-1";
if(settings.render < 0) settings.render=4;
settings.outformat="";
settings.inlineimage=true;
settings.embed=true;
settings.toolbar=false;
viewportmargin=(2,2);

defaultpen(fontsize(10pt));
size(8cm); // set a reasonable default
usepackage("amsmath");
usepackage("amssymb");
settings.tex="pdflatex";
settings.outformat="pdf";
// Replacement for olympiad+cse5 which is not standard
import geometry;
// recalibrate fill and filldraw for conics
void filldraw(picture pic = currentpicture, conic g, pen fillpen=defaultpen, pen drawpen=defaultpen)
{ filldraw(pic, (path) g, fillpen, drawpen); }
void fill(picture pic = currentpicture, conic g, pen p=defaultpen)
{ filldraw(pic, (path) g, p); }
// some geometry
pair foot(pair P, pair A, pair B) { return foot(triangle(A,B,P).VC); }
pair centroid(pair A, pair B, pair C) { return (A+B+C)/3; }
// cse5 abbreviations
path CP(pair P, pair A) { return circle(P, abs(A-P)); }
path CR(pair P, real r) { return circle(P, r); }
pair IP(path p, path q) { return intersectionpoints(p,q)[0]; }
pair OP(path p, path q) { return intersectionpoints(p,q)[1]; }
path Line(pair A, pair B, real a=0.6, real b=a) { return (a*(A-B)+A)--(b*(B-A)+B); }
// cse5 more useful functions
picture CC() {
picture p=rotate(0)*currentpicture;
currentpicture.erase();
return p;
}
pair MP(Label s, pair A, pair B = plain.S, pen p = defaultpen) {
Label L = s;
L.s = "$"+s.s+"$";
label(L, A, B, p);
return A;
}
pair Drawing(Label s = "", pair A, pair B = plain.S, pen p = defaultpen) {
dot(MP(s, A, B, p), p);
return A;
}
path Drawing(path g, pen p = defaultpen, arrowbar ar = None) {
draw(g, p, ar);
return g;
}

unitsize(5cm);

pair A = dir(140);
pair B = dir(210);
pair C = dir(330);
pair M_A = dir(270);
pair M_B = dir(55);
pair M_C = dir(175);

pair I = incenter(A, B, C);
pair D = foot(I, B, C);
pair E = B+C-D;
pair B_1 = extension(I, I+dir(90)*dir(A-I), A, B);
pair C_1 = extension(I, I+dir(90)*dir(A-I), A, C);
pair T = extension(M_C, B_1, M_B, C_1);

draw(unitcircle);
draw(A--M_A);

draw(circumcircle(T, B_1, C_1), blue);
draw(A--B--C--cycle);

dot("$A$", A, dir(A));
dot("$B$", B, dir(B));
dot("$C$", C, dir(C));
dot("$M_A$", M_A, dir(M_A));
dot("$M_B$", M_B, dir(M_B));
dot("$M_C$", M_C, dir(M_C));
dot("$I$", I, dir(I));
dot("$D$", D, dir(D));
dot("$E$", E, dir(E));
dot("$B_1$", B_1, dir(B_1));
dot("$C_1$", C_1, dir(C_1));
dot("$T$", T, dir(T));

/* TSQ Source:

!unitsize(5cm);

A = dir 140
B = dir 210
C = dir 330
M_A = dir 270
M_B = dir 55
M_C = dir 175

I = incenter A B C
D = foot I B C
E = B+C-D
B_1 = extension I I+dir(90)*dir(A-I) A B
C_1 = extension I I+dir(90)*dir(A-I) A C
T = extension M_C B_1 M_B C_1

unitcircle
A--M_A

circumcircle T B_1 C_1 blue
A--B--C--cycle

*/
