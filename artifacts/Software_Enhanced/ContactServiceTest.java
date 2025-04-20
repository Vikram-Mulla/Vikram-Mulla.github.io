
package Test;

import Contact.Contact;
import Contact.ContactService;
import org.junit.jupiter.api.*;

import static org.junit.jupiter.api.Assertions.*;

@TestMethodOrder(MethodOrderer.OrderAnnotation.class)
public class ContactServiceTest {

    private ContactService service;

    @BeforeEach
    void setUp() {
        service = new ContactService();
    }

    @Test
    @Order(1)
    void testAddContact() throws Exception {
        Contact c = service.addContact("John", "Doe", "1234567890", "123 Elm Street");
        assertEquals("John", c.getFirstName());
    }

    @Test
    @Order(2)
    void testUpdateContact() throws Exception {
        Contact c = service.addContact("Jane", "Smith", "0987654321", "456 Oak Avenue");
        service.updateFirstName(c.getContactID(), "Janet");
        assertEquals("Janet", service.getContact(c.getContactID()).getFirstName());
    }

    @Test
    @Order(3)
    void testDeleteContact() throws Exception {
        Contact c = service.addContact("Alan", "Turing", "1112223333", "789 Maple Lane");
        service.deleteContact(c.getContactID());
        Exception exception = assertThrows(Exception.class, () -> service.getContact(c.getContactID()));
        assertEquals("Contact not found", exception.getMessage());
    }

    @Test
    @Order(4)
    void testInvalidContactRetrieval() {
        Exception exception = assertThrows(Exception.class, () -> service.getContact("invalid_id"));
        assertEquals("Contact not found", exception.getMessage());
    }
}
