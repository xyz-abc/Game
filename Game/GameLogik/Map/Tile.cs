using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GameLogik.Map
{
    class Tile
    {
        public int row { get; set; }
        public int col { get; set; }

        public Terrain terrain { get; set; }
    }
}
