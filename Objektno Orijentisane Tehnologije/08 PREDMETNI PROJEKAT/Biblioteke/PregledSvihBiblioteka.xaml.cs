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
    /// Interaction logic for PregledSvihBiblioteka.xaml
    /// </summary>
    public partial class PregledSvihBiblioteka : Page
    {
        public PregledSvihBiblioteka()
        {
            InitializeComponent();

            DataContext = this;
            dataGridSveBiblioteke.ItemsSource = App.Biblioteke;
        }

        private void DataGridRow_MouseDoubleClick(object sender, MouseButtonEventArgs e)
        {
            var row = ItemsControl.ContainerFromElement((DataGrid)sender,
                                       e.OriginalSource as DependencyObject) as DataGridRow;

            if (row == null) 
                return;

            if (dataGridSveBiblioteke.SelectedItem == null)
                return;

            var biblioteka = dataGridSveBiblioteke.SelectedItem as Biblioteka_;

            // PRIKAZI LISTU SVIH KNJIGA
            if(biblioteka.Knjige.Count == 0)
            {
                MessageBox.Show("Biblioteka nema knjiga u inventaru!", "Informacija!", MessageBoxButton.OK, MessageBoxImage.Information);
            }
            else
            {
                App.ReferencaNaKnjigePoBiblioteci = biblioteka.Knjige;
                // promeni prozor u frejmu
                SpisakKnjige sk = new SpisakKnjige(biblioteka.Naziv);
                sk.ShowDialog();
                App.ReferencaNaKnjigePoBiblioteci = null;
            }
        }
    }
}
