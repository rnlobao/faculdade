//
//  ViewController.swift
//  carteirada-front-end
//
//  Created by Robson Novato Lobao on 19/09/22.
//

import UIKit

class RegisterViewController: UIViewController {

    @IBOutlet weak var registerButtonEdit: UIButton!
    
    @IBAction func registerButton(_ sender: Any) {
        //let vc = HomeViewController()
        //vc.modalPresentationStyle = .fullScreen
        //self.present(vc, animated: true, completion: nil)
    }
    override func viewDidLoad() {
        super.viewDidLoad()
        setupButton()
    }
    
    func setupButton() {
        registerButtonEdit.layer.cornerRadius = 20
        registerButtonEdit.layer.shadowColor = UIColor.black.cgColor
        registerButtonEdit.layer.shadowOffset = CGSize(width: 0.0, height: 4.0)
        registerButtonEdit.layer.shadowRadius = 4.0
        registerButtonEdit.layer.shadowOpacity = 0.5
        registerButtonEdit.layer.masksToBounds = false
    }


}

