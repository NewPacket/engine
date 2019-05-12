#pragma once

#include "EngCore\Core.h"
#include "Layer.h"

#include <vector>

namespace EngX {
	
	struct EX_API LayerStack
	{
		using LayerVector = std::vector<Layer*>;
		using LayersIter = LayerVector::iterator;

		LayerStack();
		~LayerStack();

		void PushLayer	(Layer* layer);
		void PushOverlay(Layer* overlay);

		void PopLayer	(Layer* layer);
		void PopOverlay (Layer* overlay);

		LayersIter begin() { return layers.begin(); };
		LayersIter end()   { return layers.end(); };

		LayerVector layers;
		int layersInsertIndex_;
	};

}