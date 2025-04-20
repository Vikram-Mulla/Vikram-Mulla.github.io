
package Contact;

public class Contact {
    private final String contactID;
    private String firstName;
    private String lastName;
    private String number;
    private String address;

    public Contact(String contactID, String firstName, String lastName, String number, String address) {
        this.contactID = contactID;
        this.firstName = (firstName != null && !firstName.isEmpty()) ? firstName.substring(0, Math.min(10, firstName.length())) : "NULL";
        this.lastName = (lastName != null && !lastName.isEmpty()) ? lastName.substring(0, Math.min(10, lastName.length())) : "NULL";
        this.number = (number != null && number.matches("\\d{10}")) ? number : "9999999999";
        this.address = (address != null && !address.isEmpty()) ? address.substring(0, Math.min(30, address.length())) : "NULL";
    }

    public String getContactID() { return contactID; }
    public String getFirstName() { return firstName; }
    public String getLastName() { return lastName; }
    public String getNumber() { return number; }
    public String getAddress() { return address; }

    public void setFirstName(String firstName) {
        if (firstName != null && !firstName.isEmpty())
            this.firstName = firstName.substring(0, Math.min(10, firstName.length()));
    }

    public void setLastName(String lastName) {
        if (lastName != null && !lastName.isEmpty())
            this.lastName = lastName.substring(0, Math.min(10, lastName.length()));
    }

    public void setNumber(String number) {
        if (number != null && number.matches("\\d{10}"))
            this.number = number;
    }

    public void setAddress(String address) {
        if (address != null && !address.isEmpty())
            this.address = address.substring(0, Math.min(30, address.length()));
    }
}
