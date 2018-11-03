public class Main {

    public static void main(String []args){

        double Ub = 0.84; //V
        double kTDzielE = 0.026; //V
        double R = 0.84;  //ohm
        double Is = 0.00124; //A
        double Ud = 0.00; //V
        double Ur = 0.00; //V
        double Io =0.00; //A
        double delta = 0.0001; //A
        double epsilon = 0.0001; //V

        while(Math.abs(Ub-Ur-Ud)>epsilon){
            Ur = R*Io;
            Ud = Math.log((Io/Is)+1)*kTDzielE;
            Io+=delta;
        }
        Io-=delta;
        System.out.println("Io = " + Io + ", U diody = " + Ud + ", Ur = " + Ur);
    }
}
