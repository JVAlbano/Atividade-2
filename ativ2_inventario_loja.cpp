#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>
using namespace std;

// Classe simples para representar um produto
class Produto {
public:
    string nome;
    string categoria;
    double preco;
    int estoque;

    Produto(string n, string c, double p, int e)
        : nome(n), categoria(c), preco(p), estoque(e) {}

    void exibir() const {
        cout << nome << " | Categoria: " << categoria
             << " | Preço: R$ " << preco
             << " | Estoque: " << estoque << endl;
    }
};

// Registro de venda
class Venda {
public:
    string nomeProduto;
    int quantidade;
    double total;

    Venda(string nome, int q, double t)
        : nomeProduto(nome), quantidade(q), total(t) {}
};

int main() {
    cout << "=== SISTEMA DE ESTOQUE COM STL ===" << endl;

    // Lista de produtos
    vector<Produto> produtos;
    produtos.push_back(Produto("Camiseta", "Roupas", 39.90, 50));
    produtos.push_back(Produto("Calça Jeans", "Roupas", 129.90, 20));
    produtos.push_back(Produto("Tênis", "Calçados", 249.90, 10));
    produtos.push_back(Produto("Boné", "Acessórios", 49.90, 30));
    produtos.push_back(Produto("Meia", "Roupas", 19.90, 80));

    cout << "\n--- TODOS OS PRODUTOS ---" << endl;
    for (const Produto& p : produtos) {
        p.exibir();
    }

    // Categorias únicas
    set<string> categorias;
    for (const Produto& p : produtos) {
        categorias.insert(p.categoria);
    }

    cout << "\n--- CATEGORIAS ÚNICAS ---" << endl;
    for (const string& c : categorias) {
        cout << "- " << c << endl;
    }

    // Contagem de produtos por categoria
    map<string, int> produtosPorCategoria;
    for (const Produto& p : produtos) {
        produtosPorCategoria[p.categoria]++;
    }

    cout << "\n--- PRODUTOS POR CATEGORIA ---" << endl;
    for (const auto& par : produtosPorCategoria) {
        cout << par.first << ": " << par.second << " produto(s)" << endl;
    }

    // Valor total em estoque por categoria
    map<string, double> valorPorCategoria;
    for (const Produto& p : produtos) {
        valorPorCategoria[p.categoria] += p.preco * p.estoque;
    }

    cout << "\n--- VALOR TOTAL EM ESTOQUE POR CATEGORIA ---" << endl;
    for (const auto& par : valorPorCategoria) {
        cout << par.first << ": R$ " << par.second << endl;
    }

    // Histórico de vendas
    list<Venda> historico;

    // Registro de vendas
    cout << "\n--- REGISTRANDO VENDA ---" << endl;
    string produtoVendido = "Camiseta";
    int qtd = 3;

    for (Produto& p : produtos) {
        if (p.nome == produtoVendido && p.estoque >= qtd) {
            p.estoque -= qtd;
            double total = p.preco * qtd;
            historico.push_back(Venda(p.nome, qtd, total));
            cout << "Venda realizada: " << qtd << "x " << p.nome
                 << " | Total: R$ " << total << endl;

            valorPorCategoria[p.categoria] -= total;
            break;
        }
    }

    cout << "\n--- HISTÓRICO DE VENDAS ---" << endl;
    for (const Venda& v : historico) {
        cout << v.quantidade << "x " << v.nomeProduto
             << " | Total: R$ " << v.total << endl;
    }

    cout << "\n--- ESTOQUE ATUALIZADO ---" << endl;
    for (const Produto& p : produtos) {
        p.exibir();
    }

    // Estatísticas finais
    cout << "\n=== ESTATÍSTICAS ===" << endl;
    cout << "Total de produtos cadastrados: " << produtos.size() << endl;
    cout << "Total de categorias: " << categorias.size() << endl;
    cout << "Total de vendas realizadas: " << historico.size() << endl;

    return 0;
}
