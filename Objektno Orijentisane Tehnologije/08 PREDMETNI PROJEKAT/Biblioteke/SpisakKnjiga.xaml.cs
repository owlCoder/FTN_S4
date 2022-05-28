using System.Collections.Generic;
using System.Linq;
using System.Windows;
using System.Windows.Controls;

namespace OOT_PP_PR83_PR55_2020_BIBLIOTEKA.Biblioteke
{
    /// <summary>
    /// Interaction logic for SpisakKnjige.xaml
    /// </summary>
    public partial class SpisakKnjige : Window
    {
        public SpisakKnjige(string n)
        {
            InitializeComponent();

            if (App.ReferencaNaKnjigePoBiblioteci != null)
            {
                DataContext = this;
                knjigePoBiblioteci.ItemsSource = App.ReferencaNaKnjigePoBiblioteci;

                Title = "Spisak Knjiga | Biblioteka " + n;
                naslov.Content = "SPISAK KNJIGA | BIBLIOTEKA " + n;
            }
        }

        private void pretraga_TextChanged(object sender, TextChangedEventArgs e)
        {
            List<Knjiga> pretrazeno = new List<Knjiga>();
            string unos = (sender as TextBox).Text;

            foreach (Knjiga k in App.ReferencaNaKnjigePoBiblioteci)
            {
                if (k.Naziv.ToLower().Contains(unos.ToLower()) || k.Autora.ToLower().Contains(unos.ToLower()))
                {
                    pretrazeno.Add(k);
                }
            }

            knjigePoBiblioteci.ItemsSource = pretrazeno.ToList();
        }
    }
}
