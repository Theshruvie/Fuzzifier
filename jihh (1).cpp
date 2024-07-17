//SGU
//name : shruti verma 
//student id: 23010110017
//faculty name: Mr.shakti kumar rana 


#include <stdio.h>
#include <math.h>
//user defined functions for the evaluation of mg(degree of compatibilty)
float zed(float x,float a,float b);
float tri(float x,float a,float b,float c);
float tra(float x,float b,float c,float d);
float sig(float x,float c,float d);
float min_mg(float x,float y);
float brake(float imp);

int  main(){
	//describing variables
	float sp,dist;
	float mg_sp_arr[4],mg_d_arr[4];
	float mg_sp_slow,mg_sp_med,mg_sp_f,mg_sp_vf,mg_d_c,mg_d_m,mg_d_f,mg_d_vf;
	float sa=15.0,sb=40.0,sc=65.0,sd=90.0;
	float e=5.0,f=100.0,g=200.0,h=400.0;
	float cqts[16];
	int j;
	float n_mfs_speed[4];
	float implicated_v[16];
	float dof_rule[16];
	float brakes;
	cqts[1]=10,cqts[2]=10,cqts[3]=0,cqts[4]=0,cqts[5]=70,cqts[6]=70,cqts[7]=10,cqts[8]=0,cqts[9]=100,cqts[10]=40,cqts[11]=10,cqts[12]=0,cqts[13]=100;
	cqts[14]=70,cqts[15]=10,cqts[16]=0;
	
	
	//++++++++++++++++++++++++++++++++++++++++++++fuzzification module++++++++++++++++++++++++++++++++++++++++++++++++++++
	//input statements for speed and distance
	printf("enter speed: ");
	scanf("%f",&sp);
	printf("enter distance: ");
	scanf("%f",&dist);
	
	//making the arrays of doc based on speed
	mg_sp_slow=zed(sp,sa,sb);
	mg_sp_arr[1]=mg_sp_slow;
	mg_sp_med=tri(sp,sa,sb,sc);
	mg_sp_arr[2]=mg_sp_med;
	mg_sp_f=tra(sp,sb,sc,sd);
	mg_sp_arr[3]=mg_sp_f;
	mg_sp_vf=sig(sp,sc,sd);
	mg_sp_arr[4]=mg_sp_vf;
	 
	//making the arrays of doc based on distance
	mg_d_c=zed(dist,e,f);
	mg_d_arr[1]=mg_d_c;
	mg_d_m=tri(dist,e,f,g);
	mg_d_arr[2]=mg_d_m;
	mg_d_f=tra(dist,f,g,h);
	mg_d_arr[3]=mg_sp_f;
	mg_d_vf=sig(dist,g,h);
	mg_d_arr[4]=mg_d_vf;	 
	
	printf("\n YOUR mg speed in slow fn is %f",mg_sp_slow);
	printf("\n YOUR mg speed in med fn is %f",mg_sp_med);
	printf("\n YOUR mg speed in f fn is %f",mg_sp_f);
	printf("\n YOUR mg speed in vf fn is %f",mg_sp_vf);
	
	printf("\n YOUR mg distane in close fn is %f",mg_d_c);
	printf("\n YOUR mg distance in med fn is %f",mg_d_m);
	printf("\n YOUR mg distnce in f fn is %f",mg_d_f);
	printf("\n YOUR mg distance in vf fn is %f",mg_d_vf);
	
	//++++++++++++++++++++++++++++++++inference engine(depth of firing)+++++++++++++++++++++++++++++++++++++++++
	
	//dof-depth of firing for each rule 
	dof_rule[1]=min_mg(mg_sp_arr[1],mg_d_arr[1]);
	printf("\n dof of 1: %f",dof_rule[1]);
	dof_rule[2]=min_mg(mg_sp_arr[1],mg_d_arr[2]);
	printf("\n dof of 2: %f",dof_rule[2]);
	dof_rule[3]=min_mg(mg_sp_arr[1],mg_d_arr[3]);
	printf("\n dof of 3: %f",dof_rule[3]);
	dof_rule[4]=min_mg(mg_sp_arr[1],mg_d_arr[4]);
	printf("\n dof of 4: %f",dof_rule[4]);
    dof_rule[5]=min_mg(mg_sp_arr[2],mg_d_arr[1]);
	printf("\n dof of 5: %f",dof_rule[5]);
	dof_rule[6]=min_mg(mg_sp_arr[2],mg_d_arr[2]);
	printf("\n dof of 6: %f",dof_rule[6]);
	dof_rule[7]=min_mg(mg_sp_arr[2],mg_d_arr[3]);
	printf("\n dof of 7: %f",dof_rule[7]);
	dof_rule[8]=min_mg(mg_sp_arr[2],mg_d_arr[4]);
	printf("\n dof of 8: %f",dof_rule[8]);
	dof_rule[9]=min_mg(mg_sp_arr[3],mg_d_arr[1]);
	printf("\n dof of 9: %f",dof_rule[9]);
	dof_rule[10]=min_mg(mg_sp_arr[3],mg_d_arr[2]);
	printf("\n dof of 10: %f",dof_rule[10]);
	dof_rule[11]=min_mg(mg_sp_arr[3],mg_d_arr[3]);
	printf("\n dof of 11: %f",dof_rule[11]);
	dof_rule[12]=min_mg(mg_sp_arr[3],mg_d_arr[4]);
	printf("\n dof of 12: %f",dof_rule[12]);
	dof_rule[13]=min_mg(mg_sp_arr[4],mg_d_arr[1]);
	printf("\n dof of 13: %f",dof_rule[13]);
	dof_rule[14]=min_mg(mg_sp_arr[4],mg_d_arr[2]);
	printf("\n dof of 14: %f",dof_rule[14]);
	dof_rule[15]=min_mg(mg_sp_arr[4],mg_d_arr[3]);
	printf("\n dof of 15: %f",dof_rule[15]);
	dof_rule[16]=min_mg(mg_sp_arr[4],mg_d_arr[4]);
	printf("\n dof of 16: %f",dof_rule[16]);
	
	//+++++++++++++++++++++++++++++++++++++++inference engine(implication)++++++++++++++++++++++++++++++++++++++++++++
	//implicated values for each dof
	implicated_v[1]=cqts[1]*dof_rule[1];
	implicated_v[2]=cqts[2]*dof_rule[2];
	implicated_v[3]=cqts[3]*dof_rule[3];
	implicated_v[4]=cqts[4]*dof_rule[4];
	implicated_v[5]=cqts[5]*dof_rule[5];
	implicated_v[6]=cqts[6]*dof_rule[6];
	implicated_v[7]=cqts[7]*dof_rule[7];
	implicated_v[8]=cqts[8]*dof_rule[8];
	implicated_v[9]=cqts[9]*dof_rule[9];
	implicated_v[10]=cqts[10]*dof_rule[10];
	implicated_v[11]=cqts[11]*dof_rule[11];
	implicated_v[12]=cqts[12]*dof_rule[12];
	implicated_v[13]=cqts[13]*dof_rule[13];
	implicated_v[14]=cqts[14]*dof_rule[14];
	implicated_v[15]=cqts[15]*dof_rule[15];
	implicated_v[16]=cqts[16]*dof_rule[16];	
    //+++++++++++++++++++++++++++++++++++++inference engine(aggregation)+++++++++++++++++++++++++++++++++++++++++++++++++++
    //sum of all implicated values
	int k;
	float sum;
	for(k=0;k<16;++k){
		sum=sum+implicated_v[k];
	}
	printf("\n \nSUM OF IMPLICATED VALUES :%f",sum);
	
	int s;
	float sumd;
	for(s=0;s<16;s++){
		sumd=sumd+dof_rule[s];
	}
	printf("\n \nSUM OF MINIMUM VALUES:%f",sumd);	
	
	//+++++++++++++++++++++++++++++++DEFUZZIFICATION++++++++++++++++++++++++++++++++++++++++++++
	float brake;
	brake=sum/sumd;
	printf("\n \nBRAKE :%f",brake);
	
	
}

float zed(float x,float a,float b){
	float sp,mg;
	if (x<=a){
    	mg=1;
	}
	else if(x>a & x<b){
		mg=(b-x)/(b-a);
	}
	else if (x>=b){
		mg=0;
	}
    mg;
    return (mg);
}
float tri(float x,float a,float b,float c){
	float sp,mg;
	if (x<=a){
    	mg=0;
	}
	else if(x>a & x<b){
		mg=(b-x)/(b-a);
	}
	else if(x==b){
		mg=1;
	}
	else if(x>b & x<c){
		mg=(c-x)/(c-b);
	}
	else if (x>=c){
		mg=0;
	}
    mg;
    
    return (mg);
}

//b40 c65 d90
float tra(float x,float b,float c,float d){
	float sp,mg;
	if (x<=b){
    	mg=0;
	}
	else if(x>b & x<c){
		mg=(c-x)/(c-b);
	}
	else if(x==c){
		mg=1;
	}
	else if(x>c & x<d){
		mg=(d-x)/(d-c);
	}
	else if (x>=d){
		mg=0;
	}
 
    
    return (mg);
}
float sig(float x,float c,float d){
	float sp,mg;
	if (x>c & x<d){
    	mg=(x-c)/(d-c);
	}
	else if (x>=d){
		mg=1;
	}
    mg;
    
    return (mg);
}
float min_mg(float x,float y){
	float min_2;
	if(x<=y){
		min_2=x;
	}
	else{
		min_2=y;
	}
	return (min_2);
}
