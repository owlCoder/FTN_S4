using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace OOT_PP_PR83_PR55_2020_BIBLIOTEKA.Biblioteke
{
    /// <summary>
    /// Interaction logic for BrisanjeBiblioteke.xaml
    /// </summary>
    public partial class BrisanjeBiblioteke : Page
    {
        public BrisanjeBiblioteke()
        {
            InitializeComponent();

            DataContext = this;
            dataGridSveBiblioteke.ItemsSource = App.Biblioteke;
        }

        private void dataGridSveBiblioteke_MouseDoubleClick(object sender, MouseButtonEventArgs e)
        {
            var row = ItemsControl.ContainerFromElement((DataGrid)sender,
                                       e.OriginalSource as DependencyObject) as DataGridRow;

            if (row == null)
                return;

            if (dataGridSveBiblioteke.SelectedItem == null)
                return;

            var biblioteka = dataGridSveBiblioteke.SelectedItem as Biblioteka_;

            var daNe = MessageBox.Show("Brisanje biblioteke je NEPOVRATNA OPERACIJA!\nBrisanjem biblioteke brišu se svi njeni korisnici kao i kompletan INVENTAR!\n\nDa li ste sigurni?", "Upozorenje o brisanju!", MessageBoxButton.YesNo, MessageBoxImage.Warning);

            if(daNe == MessageBoxResult.Yes)
            {
                biblioteka.Knjige.Clear();
                biblioteka.Korisnici.Clear();
                App.Biblioteke.Remove(biblioteka);

                MessageBox.Show("Biblioteka obrisana iz liste!", "Informacija", MessageBoxButton.OK, MessageBoxImage.Information);
            }
        }
    }
}
