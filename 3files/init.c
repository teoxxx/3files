#include "pluto.h"

static double alpha, pe;

/* ********************************************************************* */
void Init (double *us, double x1, double x2, double x3)
/*
 *
 *
 *
 *********************************************************************** */
{
  double vj, cs, Mach;
  double lor, vy_in, rhob, rhom, pm, pb, hb, hm, eta, vjet;
double sigma, rxyz,rxyzsq,x10,x20,x30, x10wind, x20wind, x30wind, rxyzsqwind, rxyzR;

  static int first_call = 1;



/*WIND ORIGIN COORDINATES SOS ADJUST EACH TIME AT MIDDLE OF GRID SOS
101219 try to make twin jets! At the middle of box!
*/
x10=60.0;
x20=100.0;
x30=60.0;

/*SOS IN GAMMA RAYS, distances are smaller
and orbital separation matters. Jet base is therefore other than 
the binary companion stellar wind origin.
Say binary companion is located at 25,0,25.NO! SOS! The binary separation is 4*10 to the 12 cm. SOS SUPER SOS  The orbit period is 13 days, while the domain crossing time of the jet is a mere 20min. So we take the binary companion to be still during a model run. 
*/
x10wind=400.0;
x20wind=100.0;
x30wind=400.0;
/* -- set ambient values -- */

/*THESE GO TO INITIAL DISK WIND APPROX.
*/
 rxyz = sqrt((x1-x10)*(x1-x10) + (x2-x20)*(x2-x20) + (x3-x30)*(x3-x30));
 rxyzsqwind=(x1-x10wind)*(x1-x10wind) + (x2-x20wind)*(x2-x20wind) + (x3-x30wind)*(x3-x30wind);
rxyzR=sqrt(rxyzsq);


  g_gamma = 4.0/3.0;

/*  g_unitLength = 1.67e-24; /* reference density (\rho_0) in units of gr/cmˆ3 */

/*  g_unitVelocity = 3.0e10;    /* reference velocity (v_0) in units of cm/sec */
  
/*  g_unitDensity = 1.0e10;  /* reference length (L_0) in cm */


/* PLUTO 4.1 style has vhanged in units dimensions' definition  */ 
#define UNIT_DENSITY 1.67e-24 /* reference density (\rho_0) in units of gr/cmˆ3 */
#define UNIT_LENGTH 1.0e10    /* reference length (L_0) in cm */
#define UNIT_VELOCITY 3.0e10 /* reference velocity (v_0) in units of cm/sec */

  alpha = 1.0 - g_inputParam[RM]*g_inputParam[RM]/g_inputParam[BETA];

  pe    = 0.5*g_inputParam[BETA]*g_inputParam[BM]*g_inputParam[BM];
/* 211219 activate those comments only to see if params are read OK from pluto.ini. MUST set the correct number of params on def.h, else it wont read all of them! SOS!

  printf ("early pe = %12.6e\n",pe);
  printf ("g_inputParam[BETA] = %12.6e\n",g_inputParam[BETA]);
printf ("g_inputParam[BM] = %12.6e\n",g_inputParam[BM]);

*/

/*
 pe    = 0.5*g_inputParam[BETA];
*/

/*
  us[RHO] = 1.e3;
*/
/*220520 ΣΟΣ ςινδ σετθπ μθστ ινψρεασε ατ ψομπανιον σταρ το 14 ορ 15, σο τηατ ιτ ισ αροθνδ 11 ατ βινσεπ, ι.ε. ξετ βασε, σεε νοτεβοοκ φορ ρελεωαντ ψαλψ! ΣΟΣ!*/
us[RHO] = (1000000000000000.0)/(rxyzsqwind);
/*
if ((((x1-x10)*(x1-x10))+((x3-x30)*(x3-x30))) > 20.00){
if ((((x1-x10)*(x1-x10))+((x2-x20)*(x2-x20))+((x3-x30)*(x3-x30))) < 100.00){
*/

/*
101219 SOS here disk wind center at middle SOS!
*/
if ((((x1-x10)*(x1-x10))+((x3-x30)*(x3-x30))) < 100.00){
/*211219 sos corrected this to be symmetric, both up and down!*/

/*220520 in light of re-reading fabrika04, disk wind is reset to a higher number at its source, in order to achieve 10 to the minus 4 solar mass per year output! same as stellar wind! SOS! also, fabrika04 describes a complex disk wind, dense at center but slower, and faster to the sides! A funnel is created by the jet, the funnel we als otry to achieve here!
runs slow at 10^14, try 10^13! Now try 10^12!  Now 10^12 works! gives results! But slower expansion! 
*/
if(x2>x20-20.0){
if(x2<(x20+20.0)){
us[RHO] = (20000000000000.0/(pow((x2-x20),2.0)+0.5));
us[PRS] = pe*1.0;


/*220520 try to do a lighter funnel for the jet to cross, while retaining higher density to the sides! Pressure is the same!* less than the square root of the number!*/
if ((((x1-x10)*(x1-x10))+((x3-x30)*(x3-x30))) < 35.00){
us[RHO] = (20000000000000.0/(pow((x2-x20),2.0)+0.5));

}


}
}

}





/*
NOW ACCRETION DISK SETUP
*/
/*
 if ( (x2)< (0.001+((rxyzR-3.0)/5.0))){
 if   (x2 >0.00){
*/

/* 101219 old working one around xz plane's centre!
 if ( (x2)< (0.01+((rxyz-3.0)/5.0))){
 if   (x2 >0.00){
*/
/*211219 corrected those!*/
if ( (x2)< (x20+(0.01+   ((rxyz-3.0)/5.0)   ) )   ){
 if   ( x2>(x20-(0.01+((rxyz-3.0)/5.0)    )  )   ){


/*
101219 try to centre this wind around the centre of the box! say y=50!

SOS the disk is around the black hole, not the star!!
so use x(i), not x(i)wind coordinates for it!
101219 leave x,z as is! only y i.e. x2 is affected by twin jet thingy!

*/
if ((((x1-x10)*(x1-x10))+((x3-x30) *(x3-x30))) > 50.00){
  
if ((((x1-x10)*(x1-x10))+((x3-x30)*(x3-x30))) < 1000.0){
  

/*
SOS WE REMOVE THE ACCRETION DISK, COS NO NEED TO MESS WITH UNNECESSARY
EFFECTS NOW> WE JUST FOCUS ON THE INNER JETS FOR THE TIME BEING.
*/
/*
accretion disk density assumed to fall as 1/r (not squared)
away from its center. Just a first crude approx.
*/
/*220520 we increase the accretion disk density, e.g. 10^12, so that it now still lies clearly above the stellar  wind density at the binsep location of the jet base! SOS! 
*/
 us[RHO] = (10000000000000.0/(rxyz));
/*SOS 220520 underpressure makes it stay put! Apparently!*/
    us[PRS] = 0.10 ;



}  

}
}  
}



/*
  us[RHO] = (1000.0/(rxyz*rxyz));
*/


  us[VX1] = 0.0;
  us[VX2] = 0.0;
  us[VX3] = 0.0;

  us[BX1] = 0.0;
  us[BX2] = 0.0;
  us[BX3] = 0.0;
  

us[PRS] = pe*100.0;
rxyzsq=(x1-x10)*(x1-x10) + (x2-x20)*(x2-x20) + (x3-x30)*(x3-x30);

 us[AX1] = us[AX2] = us[AX3] = 0.0;

/* 211219 try cutting this and the corresponding } at the end of the current routine
  if (first_call){
    first_call = 0;

*/
if (first_call){
    first_call = 0;
 vj   = sqrt(1.0 - 1.0/100.);

 cs   = sqrt(g_gamma*pe/(us[RHO] + pe*g_gamma/(g_gamma-1.0)));

    Mach = vj/cs;

/* 211219 cut these for now to save mach number! 
 
*/

/*
101219 set it to centre! twin jets attempt first do a half jet only there!
*/
x10=60.0;
x20=100.0;
x30=60.0;
/* -- set ambient values -- */

/*THESE GO TO INITIAL DISK WIND APPROX.
*/
 rxyz = sqrt((x1-x10)*(x1-x10) + (x2-x20)*(x2-x20) + (x3-x30)*(x3-x30));
 rxyzsq=(x1-x10)*(x1-x10) + (x2-x20)*(x2-x20) + (x3-x30)*(x3-x30);


/* 211219 DEBUG PRINTS!  */
/*
    printf ("vj = %12.6e\n",vj);
    printf ("cs = %12.6e\n",cs);
    printf ("g_gamma*pe = %12.6e\n",g_gamma*pe);
    printf ("us[RHO] + pe*g_gamma/(g_gamma-1.0)) = %22.16e\n",us[RHO] + pe*g_gamma/(g_gamma-1.0)   );
    printf ("g_gamma*pe = %12.6e\n",g_gamma*pe);
    printf ("pe = %12.6e\n",pe);

   
    printf ("Mach number = %12.6e\n",Mach);
*/

/* ----- estimate jet velocity --------- */
    
    lor   = 10.0;
/*211219 reduce things a bit here, in order to get it going t least once!
NOT ANY MOAR!*/
    vy_in = sqrt(1.0 - 1.0/lor/lor);
    rhob = g_inputParam[RHO_IN];
    rhom = 1.e3;
    pm   = pb = pe;
    hb   = 1.0 + g_gamma/(g_gamma - 1.0)*pb/rhob;
    hm   = 1.0 + g_gamma/(g_gamma - 1.0)*pm/rhom;

    eta  = rhob*hb/(rhom*hm)*lor*lor;
    vjet = sqrt(eta)/(1.0 + sqrt(eta))*vy_in;
/*211219 try no comment, no first call!
    printf (" Estimated jet velocity = %f\n",vjet);
*/
/* ---- estimate sigma (= b^2/rho) ---- */

    sigma = g_inputParam[RM]*g_inputParam[RM]*(0.5 - 2.0*log(g_inputParam[RM]));
/*
    printf (" sigma = %f\n",1.0/sigma);
 printf (" edo ore0.5 = %f\n",pe);
*/


/* 211219 end of first call if!
 }
*/
}
}
 
/* ********************************************************************* */
void Analysis (const Data *d, Grid *grid)
/* 
 *
 *
 *********************************************************************** */
{

}

/* ********************************************************************* */
void UserDefBoundary (const Data *d, RBox *box, int side, Grid *grid)
{
int     i, j, k, nv;

  double  prof,profy, lor, pr_in, vy_in, bz_in, *r;
  double  rho_in, rho_out, vx_out, vy_out, vz_out;
  double  pr_out,  bx_out, by_out, bz_out;
/*
  double  prof, lor, pr_in, vy_in, bz_in, *r, *rx, *ry, *rz, *radius, r1test;
*/ 
double  *rx, *ry, *rz, *radius, r1test;

double  pipi, theta0, theta1, phi1, speedbulk, speedx, speedy, speedz, speedx_sq, speedy_sq, speedz_sq,speedtotal, factorx, factory, factorz,speedtotal_sub,vy_sign;
int tinterval, tblob, tinteger;

 double  x10,x20,x30,x0,y0,z0,radiutskii,limit_radiutski;
/*101219 centre y=x2! twin jets!
*/
x10=60.0;
x20=100.0;
x30=60.0;
x0=x10;
y0=x20;
z0=x30;

/*221219 SUPER SOS all these stuff, we put OUTSIDE ze tot loop!! else, anti-economical!*/





pipi=3.141592653;
/*initiate theta0 at pi/8, i.e. 1/4 of 3D domain

SOS need t<1000 so that precession is lt pi/2 SOS else hqave to center ze jet and enlarge ze 
comp. domain !
*/
theta0=(pipi/8.0);

/*
theta1=((2.0*pipi/14000000.0)*g_time+theta0);
SOS 271219 we artificially set it to precess very fast, for display purposes only!*/
theta1=((2.0*pipi/140.0)*g_time+theta0);

/*
SOS NO PRECESSION WITH PHI ANGLE SET TO ZERO
phi1=(pipi/9.0);
*/
/*
phi1=0.5;
*/

phi1=0.4;
/*220520 set it to zero for now! Zero precession vs botch accr. disk and binary plane!*/
phi1=0.0;

/*
speedbulk=sqrt((vx_out*vx_out)+(vy_out*vy_out)+(vz_out*vz_out));
*/
vy_in=g_inputParam[BETA];


speedbulk=vy_in;
speedx = speedbulk*sin(phi1)*cos(theta1);
speedx_sq=speedx*speedx;
speedy_sq=speedy*speedy;
speedz_sq=speedz*speedz;
vx_out=speedx;
speedy = speedbulk*cos(phi1);
speedz = speedbulk*sin(phi1)*sin(theta1);
vy_out=0.0;
vz_out=speedz;

/*211219 SOS till herre, it works! I/B conditions work ok, geometry created!. 
Now attempting to start the jet ! SOS This sqrt gives segm. error, perhaps the speeds one of them is neg? PERHAPS! carry on from here, try to START the @#!$#$% jet! SOS DO ADD THE REMAINDER stuff in here, FROM THE ACCOMPANYING SUCH NAMED FILE!!!*/

/*271219 now try to leave this out!!
speedtotal_sub=speedx_sq+speedy_sq+speedz_sq;
if( (speedtotal_sub)<0.0){
speedtotal_sub=0.000001;

}
*/


/*
speedtotal=sqrt(speedx_sq+speedy_sq+speedz_sq);
*/
speedtotal=sqrt(speedtotal_sub);
factorx=sin(phi1)*cos(theta1);
factory=cos(phi1);
factorz=sin(phi1)*sin(theta1);

/*
original setup, with x, y, z, jet velocity components
      d->Vc[RHO][k][j][i] = rho_out - (rho_out - g_inputParam[RHO_IN])*prof;
      EXPAND(d->Vc[VX][k][j][i] = 0.0*vx_out*((1.0 - prof)+0.1);              ,
             d->Vc[VY][k][j][i] = ((vy_out - (vy_out - vy_in)))*prof;   ,
             d->Vc[VZ][k][j][i] = 0.0*vz_out*(1.0 - prof);)
*/



       
/*
        d->Vc[RHO][k][j][i] = rho_out - (rho_out - g_inputParam[RHO_IN])*prof;
*/
/*     we now save the old working setup and try to bring back precession
        EXPAND(d->Vc[VX1][k][j][i] = vx_out*(1.0 - prof);              ,
               d->Vc[VX2][k][j][i] = vy_out - (vy_out - vy_in)*prof;   ,
               d->Vc[VX3][k][j][i] = vz_out*(1.0 - prof);)  
*/
/*
sos 150915 we must set up the x z components of speed to be non zero within the prof
range, not the opposite! sos 
*/


/*280915 here we define the interval time and the blob duration time. tblob
formulates the first part of tinterval, the rest is the null time*/


/*SOS221219 DO THESE AS INPUT PARAMS IN PLUTO.INI!!! NO NEED TO EDIT THIS FILE ALL THE TIME!!! SAME WITH DISK SIZES, etc DO IT!*/
tinterval=10;
tblob=3;
/*here we set the integer part of the time*/
tinteger=(int)(g_time);


/* try to get modulus % to run on real numbers or floats
floor(a/b)*b + a%b = a
*/
/* code snippet to get the modulus of a division
int a = 5;
int b = 3;

if (a % b != 0) {
   printf("The remainder is: %i", a%b);
}
*/







  #ifdef STAGGERED_MHD
   #error Boundary not implemented for Staggered MHD
  #endif



if (side == 0){


      r = grid[IDIR].x;
       rx = grid[IDIR].x;
        ry = grid[JDIR].x;
        rz = grid[KDIR].x;

/*FROM MANUAL, in relation to to_loop! : Note: The *box structure should not be used here and staggered magnetic field variables should
not be altered. 

221219 THAT WAS IT: IT WORKS, including all the relevant density, velocity, b-field  -altering stuff! FROM NOW ON: do-it!!!*/
TOT_LOOP(k,j,i){


/*  211219 only try this, from manual!
if (d->Vc[RHO][k][j][i] < 1.e-3) {
d->Vc[RHO][k][j][i] = 1.e-3;
}
*/



  prof = 0.0;
/*
if (    (   (rx[i]-x10)*(rx[i]-x10) + (ry[j]-x20)*(ry[j]-x20) + (rz[k]-x30)*(rz[k]-x30)    ) < (g_inputParam[RM]*g_inputParam[RM])   ){

if (    (   (rx[i]-x10)*(rx[i]-x10)  + (ry[j]-x20)*(ry[j]-x20) + (rz[k]-x30)*(rz[k]-x30)    ) < (4.5)   ){
*/
if (    (   (rx[i]-x10)*(rx[i]-x10)  +  (rz[k]-x30)*(rz[k]-x30)    ) < (4.0)   ){

if( ( (ry[j]-x20)*(ry[j]-x20) )<=4.0  ){


/*
vy_sign=1.0;
if ((ry[j]-x20)<=(0.0)){
vy_sign=-1.0;
}
*/
   


/*
prof= ( ( (g_inputParam[RM]*g_inputParam[RM]-(rx[i]-x10)*(rx[i]-x10))   + (g_inputParam[RM]*g_inputParam[RM]-(ry[j]-x20)*(ry[j]-x20))+ (g_inputParam[RM]*g_inputParam[RM]-(rz[k]-x30)*(rz[k]-x30))  ) )/(3.01*g_inputParam[RM]*g_inputParam[RM]);   
*/


/*
prof= (3.0- ((rx[i]-x10)*(rx[i]-x10) + (ry[j]-x20)*(ry[j]-x20) + (rz[k]-x30)*(rz[k]-x30)) )/(4.0);
*/
/*
prof= (g_inputParam[RM]*g_inputParam[RM]- ((rx[i]-x10-)*(rx[i]-x10)   + (ry[j]-x20)*(ry[j]-x20)+ (rz[k]-x30)*(rz[k]-x30)) )/(g_inputParam[RM]*g_inputParam[RM]);       
*/

/*
prof= ( ( (g_inputParam[RM]*g_inputParam[RM]-(rx[i]-x10)*(rx[i]-x10))   + (g_inputParam[RM]*g_inputParam[RM]-(ry[j]-x20)*(ry[j]-x20))+ (g_inputParam[RM]*g_inputParam[RM]-(rz[k]-x30)*(rz[k]-x30))  ) )/(3.01*g_inputParam[RM]*g_inputParam[RM]);       
*/
/*241219 SOS SOMETHING LIKE THIS ONE, SMOOTHED AT THE ZERO AREA boundary, COULD DO IT FOR TWO SIDED THING!
profy=(ry[j]-x20)/(g_inputParam[RM]);
*/


if((ry[j]-x20)>=0.0){
profy=1.0;
}else{
profy=-1.0;
}
radiutskii=(sqrt((rx[i]-x10)*(rx[i]-x10) + (ry[j]-x20)*(ry[j]-x20) + (rz[k]-x30)*(rz[k]-x30))) ;
/*251219 SOS rm is SMALLER than 2.0, 1.0 or whatever the OUTER shell size is!! RM affects the jet inner core radius! it is 0.37 in the original pluto.ini file of toroidal RMHD jet!! SOS! REPLACE r[i] with radiutski, just move the frigging profile up from the base to the centre! ALSO CONSIDER COUNTERJET, aka profy of sorts! ADDED profy to speed direction and also to bz! SOS inner/outer core regulate bz and pressure, NOT value of velocity! SOS understand that!!! 

SOS DO Compare radiutski to original r[i], match 'em as close as possible, kepping the proportions between the two different setups, original and twin jet!
2.0 must be higher than small jet cell, else no jet starts!
SOS!! KEEP IT as simple as possible! DO IT!*/
limit_radiutski=2.0;

if (radiutskii <= limit_radiutski) {
          prof = 1.0;
          bz_in = lor*g_inputParam[BM]*g_inputParam[RM]/radiutskii;
          pr_in = alpha*pe;         
          if (radiutskii <= g_inputParam[RM]) {
            bz_in = lor*g_inputParam[BM]*radiutskii/g_inputParam[RM];
            pr_in = pe*(alpha + 2.0/g_inputParam[BETA]*(limit_radiutski - radiutskii*radiutskii/g_inputParam[RM]/g_inputParam[RM]));
          }
        }else{
          prof = 0.0;
        }  



/*
bz_in = lor*g_inputParam[BM]*g_inputParam[RM]/(rx[i]-x10); 151219 replacing r[i] with r[i] -x10*/
  /*      
pr_in = alpha*pe;   
*/

/*

d->flag[k][j][i] |= FLAG_INTERNAL_BOUNDARY;

d->Vc[RHO][k][j][i] = 10000000000000.0;
*/

/*231219 SOS this smoothed profile enough to get it going somehow! Look into it though! IS it reversed or something?  YES! careful with the first number in the RHS, cant be as much as the denom, 2.3/3 so far worked!*/



/*271219 SOS we added profy to the x,z components, in order to have opposite jets precess with 180 degrees lag, in concert!*/

EXPAND(d->Vc[VX1][k][j][i] = vx_out*(1.0 - prof)+speedx*prof*profy;              ,
               d->Vc[VX2][k][j][i] = 0.9999*profy*( vy_out - (vy_out - speedy)*prof );   ,
               d->Vc[VX3][k][j][i] = vz_out*(1.0 - prof)+speedz*prof*profy;)

/*
EXPAND(d->Vc[VX1][k][j][i] = speedx*prof;              ,
               d->Vc[VX2][k][j][i] = speedy*prof;   ,
               d->Vc[VX3][k][j][i] = speedz*prof;)
*/   
  
    
/*
EXPAND(d->Vc[VX1][k][j][i] = vx_out*(1.0 - prof)+speedx*prof;              ,
               d->Vc[VX2][k][j][i] = vy_out - (vy_out - speedy)*prof;   ,
               d->Vc[VX3][k][j][i] = vz_out*(1.0 - prof)+speedz*prof;) 
*/


/*271219 SOS need to add precession here as well somehow!!!  
WRITE IT ON PAPER IN ORDER TO DETERMINE HOW THE Bz FIELD IS PROJECTED TO x,z DURING PRECESSION! FOR NOW, only velocity precesses, NOT BZ!!! SOS CAREFUL! ONLY GOOD FOR no-precession for now!!! RESET PHI to zero for non-precession! NOT NEEDED FOR neutrinos anyway, due to small length scale and fast jet! */
EXPAND(d->Vc[BX1][k][j][i] = bx_out*(1.0 - prof);            ,
               d->Vc[BX2][k][j][i] = by_out*(1.0 - prof);            ,
               d->Vc[BX3][k][j][i] = profy*(bz_out - (bz_out - bz_in)*prof); )


      d->Vc[PRS][k][j][i] = pr_out - (pr_out - pr_in)*prof;

/*271219 old setup!
rho_in=g_inputParam[RHO_IN]*10000000000;
       rho_out=g_inputParam[RHO_IN]*10000;


/*271219 NEW SETUP: put rhoin param in pluto.ini to 10^10!
*/

rho_in=g_inputParam[RHO_IN];
       rho_out=0.000001*g_inputParam[RHO_IN];

d->Vc[RHO][k][j][i] = rho_out - (rho_out - g_inputParam[RHO_IN])*prof;



d->flag[k][j][i]|= FLAG_INTERNAL_BOUNDARY;





}


}



}
}
}



/*211219 SOS all remaining stuff is tot loop content. For now, we leave them outy, and make tot loop work with simple example from manual. Then, re-build those, step-by step!*/



  
