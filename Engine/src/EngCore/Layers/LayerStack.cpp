#include "eng_pch.h"
#include "LayerStack.h"

namespace EngX {

	LayerStack::LayerStack()
	{
		layersInsertIndex_ = 0;
	}

	LayerStack::~LayerStack() 
	{
		for (Layer* layer : layers)
			delete layer;
	}


	void LayerStack::PushLayer(Layer* layer) 
	{
		layers.emplace(layers.begin() + layersInsertIndex_, layer);
		++layersInsertIndex_;
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
			--layersInsertIndex_;
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