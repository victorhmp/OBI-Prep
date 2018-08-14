// Problema "Código" -> OBI 2017 - F2N2

#include <iostream>
#include <string>
#include <unordered_set>

#define MAXLEN 10

using namespace std;

// Manter um unordered_set para todos os prefixos já vistos.
unordered_set<string> prefix[MAXLEN + 1];
// Manter um unordered_set para todos os sufixos já vistos.
unordered_set<string> sufix[MAXLEN + 1];

int N;
string sequence;

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> sequence;

    // Verifica String lida, a partir do final
    for (int k = MAXLEN; k > 0; k--) {
      // Construtor da classe String
      // substring -> string(const string& str, int pos, int len = npos);
      string pref(sequence, 0, k);

      // Verifica se pref está em sufix[k]
      if (sufix[k].count(pref) > 0) {
        if (k == MAXLEN) {
          // Deu ruim
          cout << sequence << endl;
          return 0;
        } else {
          string suf(sequence, k, MAXLEN - k);
          // Verifica se suf está em prefix[MAXLEN - k]
          if (prefix[MAXLEN - k].count(suf) > 0) {
            // Deu ruim
            cout << sequence << endl;
            return 0;
          }
        }
      }
    }

    // Sequência é válida.
    // Insiro sufixos e prefixos.
    for (int k = MAXLEN; k >= 0; k--) {
      if (k < MAXLEN && k > 0) {
        string pref(sequence, 0, k);
        prefix[k].insert(pref);
      }
      if (k < MAXLEN) {
        string suf(sequence, k, MAXLEN - k);
        sufix[MAXLEN - k].insert(suf);
      }
    }
  }

  cout << "ok" << endl;

  return 0;
}