#include    <math.h>
#include    <iostream>
#include    <stdlib.h>
#include    <cstdlib>
#include    <cstdio>
#include    "Quaternion.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"

#define MAXLINE 512 

/*
 * =====================================================================================
 *
 *       Filename:  merge.cpp
 *
 *    Description:  merges reflection and shoreline feature points
 *
 *        Version:  1.0
 *        Created:  07/02/2014 04:26:38 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Hong-Bin Yoon (), yoon48@illinois.edu
 *   Organization:  
 *
 * =====================================================================================
 */



#include	<stdlib.h>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
    int
main ( int argc, char *argv[] )
{  
    line	= (char *) calloc ( (size_t)(MAXLINE), sizeof(char) );
    if ( line==NULL ) {
        fprintf ( stderr, "\ndynamic memory allocation failed\n" );
        exit (EXIT_FAILURE);
    }

    /*  Total Number of Features */
    int N = 5;
    int n = 0;
    bool refl; // fills with reflection data when true
    FILE* fp_r = fopen("REFLECTION_PATH" , 'r'); // TODO: EDIT PATHS
    FILE* fp_s = fopen("SHORELINE_PATH", 'r');   
    while(1)
    {
        refl = true;
        while(n<N)
        {
            if(refl) // fill with reflection
            {
                if( (fgets(line,MAXLINE,fp_r ))==NULL )
                    err_sys("fgets reflection pib");
                
                if( line[0] == '\n' )
                {
                    refl = false;
                    continue;
                }
                else
                {
                    printf("%s",line);
                    n++;
                }
            }
            else  // fill with shoreline
            {


                if( (fgets(line,MAXLINE,fp_s ))==NULL )
                    err_sys("fgets reflection pib");

                if( line[0] == '\n' )
                {

                    continue;
                }
                else
                {
                    printf("%s",line);
                    n++;
                }
            }
        }

        while((fgets(line,MAXLINE,fp_s ))!=NULL )  // reads rest of the shoreline
        {
            if( line[0] == '\n' )
            {
                printf("%s",line);
                continue;
            }
        }

    }
    free (line);
    line	= NULL;
    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
