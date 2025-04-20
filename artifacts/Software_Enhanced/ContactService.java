
package Contact;

import java.util.HashMap;
import java.util.Map;

public class ContactService {
    private Map<String, Contact> contactMap = new HashMap<>();
    private int idCounter = 0;

    public Contact addContact(String firstName, String lastName, String number, String address) {
        String contactID = String.valueOf(idCounter++);
        Contact contact = new Contact(contactID, firstName, lastName, number, address);
        contactMap.put(contactID, contact);
        return contact;
    }

    public Contact getContact(String contactID) throws Exception {
        if (!contactMap.containsKey(contactID)) throw new Exception("Contact not found");
        return contactMap.get(contactID);
    }

    public void deleteContact(String contactID) throws Exception {
        if (!contactMap.containsKey(contactID)) throw new Exception("Contact not found");
        contactMap.remove(contactID);
    }

    public void updateFirstName(String contactID, String newFirstName) throws Exception {
        getContact(contactID).setFirstName(newFirstName);
    }

    public void updateLastName(String contactID, String newLastName) throws Exception {
        getContact(contactID).setLastName(newLastName);
    }

    public void updateNumber(String contactID, String newNumber) throws Exception {
        getContact(contactID).setNumber(newNumber);
    }

    public void updateAddress(String contactID, String newAddress) throws Exception {
        getContact(contactID).setAddress(newAddress);
    }

    public void displayAllContacts() {
        for (Contact contact : contactMap.values()) {
            System.out.println("ID: " + contact.getContactID());
            System.out.println("First Name: " + contact.getFirstName());
            System.out.println("Last Name: " + contact.getLastName());
            System.out.println("Phone: " + contact.getNumber());
            System.out.println("Address: " + contact.getAddress());
            System.out.println();
        }
    }
}
