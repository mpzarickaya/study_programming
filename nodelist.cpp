#include <iostream>
#include <string>
using namespace std;

struct spotifyuser {
    int id;
    int age;
    string country;
    string favgenre;
    spotifyuser *next;
};

void AddFirst (spotifyuser*& data, int id1, int age1, string country1, string favgenre1){
    spotifyuser *newspotifyuser = new spotifyuser;
    newspotifyuser -> id = id1;
    newspotifyuser -> age = age1;
    newspotifyuser -> country = country1;
    newspotifyuser -> favgenre = favgenre1;
    spotifyuser *tmp = data;
    while (tmp != NULL){
        if (tmp -> id == id1){
            cout << "User with this id already in list\n" << endl;
            return;
        }
        tmp = tmp -> next;
    }
    newspotifyuser -> next = data;
    data = newspotifyuser;
    return;
}

void PrintList (spotifyuser *data){
    if (data == NULL){
        cout << "This list is empty" << endl;
        return;
    }
    spotifyuser *tmp = data;
    while (tmp != NULL){
        cout << "Spotify user id: " << tmp -> id << " age: " << tmp -> age << " country: " << tmp -> country << " favourite genre: "  << tmp -> favgenre << endl;
        tmp = tmp -> next;
    }
}

int main() {
    spotifyuser *head = NULL;

    int id1 = 1;
    int age1 = 16;
    string country1 = "Belarus";
    string favgenre1 = "Pop";

    int id2 = 2;
    int age2 = 24;
    string country2 = "Germany";
    string favgenre2 = "Rock";

    PrintList(head);
    cout << "++++++++++++++++++++++++++++++++++\n";

    AddFirst(head, id1, age1, country1, favgenre1);
    PrintList(head);
    cout << "===================================\n";

    AddFirst(head, id2, age2, country2, favgenre2);
    PrintList(head);
}
