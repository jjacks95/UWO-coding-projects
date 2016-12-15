/*Program name - AddressBook.java
 * 
 * The purpose of this program is to build an address book including different criteria, such as first middle and last name
 *  that can be called into other programs if necessary later
 *  
 * Athabasca University ID - 3181465
 * Author- Joshua Samuel Jackson
 * Date - July 15, 2014
 */

package assignment1;
//defining each part of the class, and each item to be stored in the program
class AddressBook{
    private String firstName;
    String middleName;
    String lastName;
    String homeAddress;
    String businessPhone;
    String homePhone;
    String cellPhone;
    String skypeId;
    String facebookId;
    String personalWebsite;
    int time;
    int years;

    public
    AddressBook(String first, String last){
        this.firstName=first;
        this.lastName=last;
    }
  
    //get methods
    AddressBook(){};
    String getFirstName(){return firstName;}
    String getMiddleName(){return middleName;}
    String getLastName(){return lastName;}
    String getHomeAddress(){return homeAddress;}
    String getBusinessPhone(){return businessPhone;}
    String getHomePhone(){return homePhone;}
    String getCellPhone(){return cellPhone;}
    String getSkypeId(){return skypeId;}
    String getFacebookId(){return facebookId;}
    String getPersonalWebsite(){return personalWebsite;}

    //set methods
    void setFirstName(String firstName){
        this.firstName = firstName;
    }
    
    void setMiddleName(String middleName){
        this.middleName = middleName;
    }

    void setLastName(String lastName){
        this.lastName = lastName;
    }

    void setHomeAddress(String homeAddress ){
        this.homeAddress = homeAddress;
    }

    void setBusinessPhone(String businessPhone){
        this.businessPhone = businessPhone;
    }

    void setHomePhone(String homePhone){
        this.homePhone = homePhone;
    }

    void setCellPhone(String cellPhone){
        this.cellPhone = cellPhone;
    }

    void setSkypeId(String skypeId){
        this.skypeId=skypeId;
    }

    void setFacebookId(String facebookId){
        this.facebookId = facebookId;
    }

    void setPersonalWebsite(String personalWebsite){
        this.personalWebsite = personalWebsite;
    }
    static int compareNames(String name1, String name2){
        return name1.compareTo(name2);
    }
    //system outputs to check the program is working
   void print(){
        System.out.println("firstName: "    +this.getFirstName()        );
        System.out.println("middleName: "   +this.getMiddleName()       );
        System.out.println("lastName: "     +this.getLastName()         );
        System.out.println("homeAddress: "  +this.getHomeAddress()      );
        System.out.println("BusinessPhone:" +this.getBusinessPhone()    );
        System.out.println("HomePhone: "    +this.getHomePhone()        );
        System.out.println("CellPhone: "    +this.getCellPhone()        );
        System.out.println("SkypeId: "      +this.getSkypeId()          );
        System.out.println("FacebookId: "   +this.getFacebookId()       );
        System.out.println("Website: "      +this.getPersonalWebsite()  );
   }
   /*this is the check process for AddressBook.java using these methods to 
    * ensure the program does not have any flaws, and produces the proper outputs
    */
   
 /*   
    public static void main(String [] args)
    {
        AddressBook js= new AddressBook();
        js.setFirstName("John");
        js.setMiddleName("Mark");
        js.setLastName("Smith");
        js.setHomeAddress("123 Some Street, Vancouver, BC");
        js.setBusinessPhone("604.987.2343");
        js.setHomePhone("778.234.3383");
        js.setCellPhone("778.889.23423");
        js.setSkypeId("john mark smith");
        js.setFacebookId("jmsmith");
        js.setPersonalWebsite("http://js.personalsite.google.com");
        js.setTime(243);
        js.setYears(5);
        //js.print();
        AddressBook EB = new AddressBook("Elena","Brandon",341,1);
        AddressBook TM = new AddressBook("Thomas","Molson",273,2);
        AddressBook HW = new AddressBook("Hamilton","Winn",278,5);
        AddressBook SS = new AddressBook("Suzie","Saranding",329,7);
        AddressBook PW = new AddressBook("Philip","Winne",445,9);
        AddressBook AT = new AddressBook("Alex","Trebok",275,3);
        AddressBook EP = new AddressBook("Emma","Pivoto",275,4);
        AddressBook JL = new AddressBook("John","Lenthen",243,1);
    } */
}
