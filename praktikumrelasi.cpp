#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
// ============================================================
// CLASS USER (Parent)
// ============================================================
class User {
protected:
    static int globalId;  // shared counter untuk semua user
    int    id;
    string nama;
    string email;
 
public:
    User(string nama, string email)
        : nama(nama), email(email) {
        this->id = generateId();
    }
 
    int generateId() {
        return ++globalId;
    }
 
    int getId()       const { return id; }
    string getNama()  const { return nama; }
    string getEmail() const { return email; }
 
    virtual ~User() {}
};
 
int User::globalId = 0;
 
 
// ============================================================
// CLASS MEMBER (turunan User)
// ============================================================
class Member : public User {
private:
    bool status;  // true = aktif, false = nonaktif
 
public:
    Member(string nama, string email)
        : User(nama, email), status(true) {}
 
    bool getStatus() const { return status; }
    void setStatus(bool s) { status = s; }
 
    void showProfile() const {
        cout << "===== Profil Member =====" << endl;
        cout << "ID     : " << id    << endl;
        cout << "Nama   : " << nama  << endl;
        cout << "Email  : " << email << endl;
        cout << "Status : " << (status ? "Aktif" : "Nonaktif") << endl;
        cout << "=========================" << endl;
    }
};
 
 
// ============================================================
// CLASS ADMIN (turunan User)
// ============================================================
class Admin : public User {
public:
    Admin(string nama, string email)
        : User(nama, email) {}
 
    void showAllMember(const vector<Member*>& members) const {
        cout << "\n===== Daftar Semua Member =====" << endl;
        if (members.empty()) {
            cout << "(Belum ada member terdaftar)" << endl;
        }
        for (const Member* m : members) {
            cout << "[" << m->getId() << "] "
                 << m->getNama()
                 << " - " << m->getEmail()
                 << " | " << (m->getStatus() ? "Aktif" : "Nonaktif")
                 << endl;
        }
        cout << "================================" << endl;
    }
 
    void toggleActivationMember(vector<Member*>& members, int targetId) const {
        for (Member* m : members) {
            if (m->getId() == targetId) {
                m->setStatus(!m->getStatus());
                cout << "Status member '" << m->getNama() << "' diubah menjadi "
                     << (m->getStatus() ? "Aktif" : "Nonaktif") << "." << endl;
                return;
            }
        }
        cout << "Member dengan ID " << targetId << " tidak ditemukan." << endl;
    }
};
 
 
// ============================================================
// MAIN — contoh penggunaan
// ============================================================
int main() {
    // Buat admin
    Admin admin("Zaki", "zaki@example.com");
 
    // Buat beberapa member
    Member* m1 = new Member("Budi",  "budi@mail.com");
    Member* m2 = new Member("Sari",  "sari@mail.com");
    Member* m3 = new Member("Deni",  "deni@mail.com");
 
    vector<Member*> daftarMember = { m1, m2, m3 };
 
    // Tampilkan semua member
    admin.showAllMember(daftarMember);
 
    // Tampilkan profil satu member
    m1->showProfile();
 
    // Toggle status member dengan ID 2 (Sari)
    admin.toggleActivationMember(daftarMember, 2);
 
    // Tampilkan ulang setelah perubahan
    admin.showAllMember(daftarMember);
 
    // Bersihkan memory
    for (Member* m : daftarMember) delete m;
 
    return 0;
}