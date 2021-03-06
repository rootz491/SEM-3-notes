#include <mega16.h>
#include <delay.h>

int up = 0, down = 0, timer = 0, current=0;

void main() {
    PORTC=0b00000000;
    DDRC=0b00001111;
    
    PORTD=0b00000111;
    DDRD=0b00000000;
    
    while (1) {
        if (PIND.0==0) {
            delay_ms(250);
            up++;
        }
        if (PIND.1==0) {
            delay_ms(250);
            if (up > 0 || ((current - down) > 0))
                down++;
        }
        
                         
        if (PIND.2==0 && (up > 0 || down > 0)) {
            delay_ms(250);
            current += (up - down);
            timer=5;
            
            // going up
            while (up) {         
                PORTC.0=1;
                PORTC.1=0;
                PORTC.3=0;
                
                PORTC.2=1;
                delay_ms(1000);
                PORTC.2=0;
                PORTC.0=0;
                delay_ms(150);
                
                up--;  
            }
            PORTC=0x00; 
            
            delay_ms(300);     
            
            // going down
            while (down) {
                PORTC.0=0;
                PORTC.1=1;
                PORTC.2=0;
               
                PORTC.3=1;
                delay_ms(1000);
                PORTC.3=0;
                PORTC.1=0;
                delay_ms(150);
            
                down--;  
            }          
            PORTC=0x00;
            // back to GROUND floor after 5 sec.
           
            if (current > 0) {              
                // waiting for UP or down to be pressed for 5 seconds ....
                do {  
                    delay_ms(200);
                    if (PIND.0==0){
                        delay_ms(200);
                        up++;
                        break;
                    }    
                    if (PIND.1==0){
                        delay_ms(200);
                        if (up > 0 || ((current - down) > 0))
                            down++;
                        break;
                    }
                    delay_ms(200);
                    if (PIND.0==0){
                        delay_ms(200);
                        up++;
                        break;
                    }    
                    if (PIND.1==0){
                        delay_ms(200);
                        if (up > 0 || ((current - down) > 0))
                            down++;
                        break;
                    }
                    delay_ms(200);
                    if (PIND.0==0){
                        delay_ms(200);
                        up++;
                        break;
                    }    
                    if (PIND.1==0){
                        delay_ms(200);
                        if (up > 0 || ((current - down) > 0))
                            down++;
                        break;
                    }
                    delay_ms(200);
                    if (PIND.0==0){
                        delay_ms(200);
                        up++;
                        break;
                    }    
                    if (PIND.1==0){
                        delay_ms(200);
                        if (up > 0 || ((current - down) > 0))
                            down++;
                        break;
                    }
                    delay_ms(200);
                    if (PIND.0==0){
                        delay_ms(200);
                        up++;
                        break;
                    }    
                    if (PIND.1==0){
                        delay_ms(200);
                        if (up > 0 || ((current - down) > 0))
                            down++;
                        break;
                    }
                    timer--;
                } while (timer > 0);
                
                // going back to ground
                if (timer == 0) {
                    while (current>0) {
                        PORTC.0=0;
                        PORTC.1=1;
                        PORTC.2=0;
                       
                        PORTC.3=1;
                        delay_ms(1000);
                        PORTC.3=0;
                        PORTC.1=0;
                        delay_ms(100);
                                    
                        current--;    
                    }
                }
                PORTC.1=0;
            }
                 
            timer=5;      
        }
        
        PORTC=0b00000000;
        PORTD=0b00000111;
        
        if (current < 0)
            current = 0;
    }                
}