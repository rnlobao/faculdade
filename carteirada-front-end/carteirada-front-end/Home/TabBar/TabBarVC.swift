//
//  TabBarVC.swift
//  carteirada-front-end
//
//  Created by Robson Novato Lobao on 20/09/22.
//

import UIKit

class TabBarVC: UITabBar {
    
    private var shapeLayer: CALayer?
    
    private func addShape() {
        let shapeLayer = CAShapeLayer()
        shapeLayer.path = createPath()
        shapeLayer.fillColor = UIColor.gray.cgColor
        shapeLayer.lineWidth = 1.0
        
        if let oldLayerShape = self.shapeLayer {
            self.layer.replaceSublayer(oldLayerShape, with: shapeLayer)
        } else {
            self.layer.insertSublayer(shapeLayer, at: 0)
        }
        self.shapeLayer = shapeLayer
    }
    
    override func draw(_ rect: CGRect) {
        self.addShape()
        self.shapeLayer?.backgroundColor = UIColor.gray.cgColor
        self.backgroundColor = UIColor.gray
    }
    
    
    func createPath() -> CGPath {
        let height: CGFloat = 80.0
        let path = UIBezierPath()
        return path.cgPath
    }

}
