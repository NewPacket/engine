#include "eng_pch.h"
#include "LayerStack.h"

namespace EngX {

	LayerStack::LayerStack()
	{
		layersInsert = layers.begin();
	}

	LayerStack::~LayerStack() 
	{
		for (Layer* layer : layers)
			delete layer;
	}


	void LayerStack::PushLayer(Layer* layer) 
	{
		layersInsert = layers.emplace(layersInsert, layer);
	}
	void LayerStack::PushOverlay(Layer* overlay)
	{
		layers.emplace_back(overlay);
	}

	void LayerStack::PopLayer(Layer* layer) 
	{
		auto it = std::find(layers.begin(), layers.end(), layer);
		if (it != layers.end())
		{
			layers.erase(it);
			layersInsert--;
		}
	}

	void LayerStack::PopOverlay(Layer* overlay) 
	{
		auto it = std::find(layers.begin(), layers.end(), overlay);
		if (it != layers.end())
		{
			layers.erase(it);
		}
	}
}