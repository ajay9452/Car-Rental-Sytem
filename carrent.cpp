#include<bits/stdc++.h>
using namespace std;
#define pi 3.14159265358979323846
#define earth_radius 6371.0
// function convert degree to radian
double userlatitude,userlongitude;
double degreetoradin(double deg)
{
	return deg*pi/180;
}

double distanceOnEarth(double la2,double lo2)
{
	
	double diff_longitude,central_angle;
	double lat2=degreetoradin(la2);
	double lot2=degreetoradin(la2);
	double userla=degreetoradin(userlatitude);
	double userlo=degreetoradin(userlongitude);
	diff_longitude=lot2-userlo;

	//great circle distance formula.
	central_angle=acos(sin(userla)*sin(lat2)+cos(userla)
		*cos(lat2)*cos(diff_longitude));
	return earth_radius*central_angle;


}
ifstream carRental_list("cardetail_list.json");
    ofstream yourans("yourans_list.json");

    struct maincode
    {
     /* i and j are used to access various 
    elements of the char arrays. x is used 
    to measure the size of the element of 
    latitude_as_string array. y is used to 
    measure the size of the element of 
    longitude_as_string array. m is used 
    to measure the size of the element 
    of id_as_string array. n is used to 
    measure the size of the element of 
    name array. f keeps count of " " " 
    symbol. fi keeps count of " : " symbol. 
    */

    long long int length,i,j,x,y,m,n,f,fi,id[100000];
    char latitude_as_string[1000];
    char longitude_as_string[1000],id_as_string[1000],name[1000];
    double lat2d,lon2d;
    string line;


    void distance_calculate()
    {
      if(distanceOnEarth(lat2d,lon2d)<=50.0000)
      {
        id[i]=atoll(id_as_string);
        i++;
        yourans<<"{\"user_id\": "<<id[i-1]<<",\"name\": "<<name<<"}"<<endl;
      }
    }
      void readfile()
      {
        if(carRental_list.is_open())
        {
            while(getline(carRental_list,line))
            {
                f = 0; x = 0; y = 0; fi = 0; m = 0, n = 0; 
                length = line.size(); 
  
                for (j = 0; j < length; j++) 
                { 
                      
                    if (line[j] == '"') 
                        f++; 
  
                    else if (line[j] == ':') 
                        fi++; 
                          
                    // To get latitude of the location.     
                    if (f == 3) 
                    { 
                        j++; 
  
                        while (line[j] != '"') 
                        { 
                            latitude_as_string[x] = line[j]; 
                            x++; j++; 
                        } 
  
                        j--; latitude_as_string[x] = '\0'; 
                    } 
                      
                    // To get longitude of the location. 
                    else if (f == 13) 
                    { 
                        j++; 
  
                        while (line[j] != '"') 
                        { 
                            longitude_as_string[y] = line[j]; 
                            y++; j++; 
                        } 
  
                        j--; longitude_as_string[y] = '\0'; 
                    } 
                      
                    // To get id of the friend. 
                    if (fi == 2) 
                    { 
                        j += 2; 
  
                        while (line[j] != ',') 
                        { 
                            id_as_string[m] = line[j]; 
                            m++; j++; 
                        } 
  
                        j--; id_as_string[m] = '\0'; 
                        fi++; 
                    } 
                      
                    // To get name of the friend. 
                    else if (fi == 4) 
                    { 
                        j += 2; 
  
                        while (line[j] != ',') 
                        { 
                            name[n] = line[j]; 
                            n++; j++; 
                        } 
  
                        j--; name[n] = '\0'; 
                        fi++; f += 2; 
                    } 
                } 
  
                // Converting latitude and longitude 
                // in string to float. 
                lat2d = atof(latitude_as_string); 
                lon2d = atof(longitude_as_string); 
                distance_calculate();
            }
        }
        carRental_list.close();
        yourans.close();
      } 
};

int main()
{
	cout<<"\nUser input your latitude and longitude detals\nlatiude = ";
	cin>>userlatitude;
	cout<<"\nlongitude = ";
	cin>>userlongitude;
	maincode obj;

    obj.readfile();
}
